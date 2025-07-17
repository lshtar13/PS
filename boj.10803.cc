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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)

cll N = 1e4, M = 100;
ll n, m, dp[N + 1][M + 1] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, 0x3f3f3f3f, sizeof(dp));
  cin >> n >> m;
  FOR(len, 1, m + 1) { dp[len][len] = 1; }

  FOR(a, 1, n + 1) FOR(b, 1, m + 1) {
    if (a > b * 3) {
      dp[a][b] = dp[a - b][b] + 1;
      continue;
    }

    FOR(na, 1, a / 2 + 1) {
      dp[a][b] = min(dp[a][b], dp[na][b] + dp[a - na][b]);
    }
    FOR(nb, 1, b / 2 + 1) {
      dp[a][b] = min(dp[a][b], dp[a][nb] + dp[a][b - nb]);
    }
  }

  cout << dp[n][m] << "\n";

  return 0;
}