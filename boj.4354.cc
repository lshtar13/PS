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
cll N = 1e6;

bool check(string &str, ll n, ll p) {
  if (n % p) {
    return false;
  }

  for (ll i = 0; i < n; ++i) {
    if (str[i] != str[i % p]) {
      return false;
    }
  }

  return true;
}

ll solve(string str) {
  ll n = str.length(), pi[N] = {};
  pi[0] = 0;

  for (ll i = 1, p; i < n; ++i) {
    p = pi[i - 1];
    while (p > 0 && str[p] != str[i]) {
      p = pi[p - 1];
    }

    if (str[p] == str[i]) {
      pi[i] = p + 1;
    }
  }

  ll result = n;
  for (ll p = pi[n - 1], len = n; p; p = pi[p - 1]) {
    if (p && check(str, len, p)) {
      result = len = p;
    }
  }

  return n / result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (string input; cin >> input && input != ".";) {
    cout << solve(input) << "\n";
  }

  return 0;
}