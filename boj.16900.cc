#include <bits/stdc++.h>

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

cll N = 5e5, K = 1e6;
ll n, pi[N] = {}, k;
char s[N + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> k;
  n = strlen(s);
  pi[0] = 0;
  for (ll i = 1, prv; i < n; ++i) {
    prv = pi[i - 1];
    while (prv && s[prv] != s[i]) {
      prv = pi[prv - 1];
    }

    if (s[prv] == s[i]) {
      pi[i] = prv + 1;
    } else {
      pi[i] = 0;
    }
  }

  ll result = n;
  for (ll i = 2; i <= k; ++i) {
    result += (n - pi[n - 1]);
  }

  cout << result << "\n";

  return 0;
}