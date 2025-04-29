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

cll N = 100, L = N, R = N, MOD = 1e9 + 7;
ll n, l, r, dp[N + 1][L + 1][R + 1] = {{{}}};
// 가장 큰 수 부터 탐색하여 양옆으로 붙이는 경우, 중간에 넣는 경우 고려...

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, l, r;
  cin >> n >> l >> r;

  dp[0][1][1] = 1;
  for (ll num = 1; num <= n; ++num) {
    for (ll left = 1; left <= n; ++left) {
      for (ll right = 1; right <= n; ++right) {
        dp[num][left][right] += dp[num - 1][left][right] * (num - 1);
        dp[num][left][right] %= MOD;
        dp[num][left][right] += dp[num - 1][left - 1][right];
        dp[num][left][right] %= MOD;
        dp[num][left][right] += dp[num - 1][left][right - 1];
        dp[num][left][right] %= MOD;
      }
    }
  }
  cout << dp[n - 1][l][r] << "\n";
  return 0;
}
