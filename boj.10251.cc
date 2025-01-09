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

cll M = 100, N = 100, L = 10, G = 1e6, INF = 1e7;
ll m, n, fuels[M][N][2] = {{{}}};
ll dp[M][N][2][M + N] = {{{{}}}};
// 0 => rightside, 1 => downside;

bool isValid(ll i, ll l) { return i >= 0 && i < m && l >= 0 && l < n; }

ll solve(ll speed, ll fuel) {
  ll result;

  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0][0][0][0] = dp[0][0][1][0] = 0;
  for (ll i = 1; i < n; ++i) {
    dp[0][i][0][0] = dp[0][i - 1][0][0] + fuels[0][i - 1][0];
    dp[0][i][1][1] = dp[0][i][0][0];
  }
  for (ll i = 1; i < m; ++i) {
    dp[i][0][0][1] = dp[i - 1][0][0][1] + fuels[i - 1][0][1];
    dp[i][0][1][0] = dp[i][0][0][1];
  }

  for (ll i = 1; i < m; ++i) {
    for (ll l = 1; l < n; ++l) {
      // hererer
    }
  }

  return result != INF ? result : -1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t, l, g;
  cin >> t;

  while (t--) {
    cin >> m >> n >> l >> g;
    memset(fuels, -1, sizeof(fuels));
    for (ll i = 0; i < m; ++i) {
      for (ll j = 0; j < n - 1; ++j) {
        cin >> fuels[i][j][0];
      }
    }

    for (ll i = 0; i < m - 1; ++i) {
      for (ll j = 0; j < n; ++j) {
        cin >> fuels[i][j][1];
      }
    }

    cout << solve(l, g) << "\n";
  }

  return 0;
}