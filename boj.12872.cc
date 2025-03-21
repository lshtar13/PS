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

cll N = 100, M = 100, P = 100, MOD = 1e9 + 7;
ll n, m, p, dp[N + 1][P + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> p;

  dp[0][0] = 1;
  for (ll num = 1; num <= n; ++num) {
    dp[num][0] = 1;
    for (ll len = 1; len <= p; ++len) {
      if (len >= m) {
        dp[num][len] = dp[num][len - m] * dp[num - 1][m];
      } else if (len <= num) {
        dp[num][len] = dp[num - 1][len - 1] * (len);
      }
    }
  }

  cout << dp[n][p] << "\n";

  return 0;
}