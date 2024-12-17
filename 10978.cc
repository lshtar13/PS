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

cll N = 20, STATUS = 1 << 20;
ll t, n;

ll cases(ll status, ll idx, vll &dp) {
  if (idx >= n) {
    return 2;
  } else if (dp[status]) {
    return dp[status];
  }

  dp[status] = 1;
  for (ll dorm = 0, msk; dorm < n; ++dorm) {
    msk = (1 << dorm);
    if ((status & msk) || (idx == dorm)) {
      continue;
    }

    dp[status] += cases(status | msk, idx + 1, dp) - 1;
  }

  return dp[status];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> n;
    vll dp(1 << n);
    cout << cases(0, 0, dp) - 1 << "\n";
  }

  return 0;
}