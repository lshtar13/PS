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

cll N = 20, L = 1e4, K = 1e3;

ll solve() {
  ll n, l, stats[N][2] = {}, dp[2][L + 1] = {{}}, result = 0;
  memset(dp, -1, sizeof(dp));
  scanf("%lld %lld", &n, &l);
  for (ll i = 0; i < n; ++i) {
    scanf("%lld %lld", &stats[i][0], &stats[i][1]);
  }

  dp[1][0] = 0;
  for (ll cur, prv, i = 0; i < n; ++i) {
    cur = i % 2, prv = !cur;
    for (ll k = 0; k <= l; ++k) {
      dp[cur][k] = dp[prv][k];
      if (k >= stats[i][1] && dp[prv][k - stats[i][1]] != -1) {
        dp[cur][k] = max(dp[cur][k], dp[prv][k - stats[i][1]] + stats[i][0]);
      }

      result = max(result, dp[cur][k]);
    }
  }

  return result;
}

int main(void) {
  ll t;
  scanf("%lld", &t);

  for (ll i = 1; i <= t; ++i) {
    printf("#%lld %lld\n", i, solve());
  }

  return 0;
}