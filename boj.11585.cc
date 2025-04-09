#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef queue<ll> qll;
typedef queue<pll> qpll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

cll N = 1e6;
ll n;
char src[2 * N + 2] = {}, tgt[N + 1] = {};

void getPi(char str[], ll pi[]) {
  for (ll i = 1, prv; i < n; ++i) {
    prv = pi[i - 1];
    while (prv && str[prv] != str[i]) {
      prv = pi[prv - 1];
    }

    if (str[prv] == str[i]) {
      pi[i] = prv + 1;
    } else {
      pi[i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin.ignore();
  for (ll i = 0; i < 2; ++i) {
    ll idx = 0;
    string input;
    getline(cin, input);
    for (auto &c : input) {
      if (c == ' ' || c == '\n') {
        continue;
      }
      if (i) {
        src[idx++] = c;
      } else {
        tgt[idx++] = c;
      }
    }
  }

  ll pi[N] = {};
  getPi(tgt, pi);

  strncpy(src + n, src, n);
  ll st = 0, prv = 0, pt = 0, ans = 0, result = 0;
  while (true) {
    if (src[pt] == tgt[ans]) {
      ++pt, ++ans;
    } else if (ans) {
      ans = pi[ans - 1];
    } else {
      ++pt;
    }

    if (ans == n) {
      ++result;
      ans = pi[n - 1];
    }

    if (pt == 2 * n - 1) {
      break;
    }
  }

  ll div = gcd(result, n);
  cout << result / div << "/" << n / div << "\n";

  return 0;
}