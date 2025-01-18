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

cll N = 16, INF = N * 36 + 1;
ll n, p, genStatus = 0, costs[N][N] = {{}}, dp[1 << N] = {};
// dp[0] => minCost, dp[1] => num of needed stations for minCost

ll num(ll status) {
  ll result = 0;
  for (ll i = 0; i < n; ++i) {
    result += bool(status & (1 << i));
  }

  return result;
}

ll find(ll status) {
  if (dp[status] <= INF) {
    return dp[status];
  }

  ll result = INF;
  for (ll prvStatus, prvCost, station = 0; station < n; ++station) {
    if (!(status & (1 << station))) {
      continue;
    } else if (genStatus & (1 << station)) {
      continue;
    }

    prvStatus = status & ~(1 << station);
    prvCost = find(prvStatus);
    for (ll prvStation = 0; prvStation < n; ++prvStation) {
      if (!(prvStatus & (1 << prvStation))) {
        continue;
      }

      result = min(result, prvCost + costs[prvStation][station]);
    }
  }
  return dp[status] = result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR2(i, l, n, n) { cin >> costs[i][l]; }
  FOR1(i, n) {
    char c;
    cin >> c;
    if (c == 'Y') {
      genStatus |= (1 << i);
    }
  }
  cin >> p;

  memset(dp, 0x3f3f3f, sizeof(dp));
  dp[genStatus] = 0;
  ll result = INF;
  for (ll status = 0; status < (1 << n); ++status) {
    if (num(status | genStatus) < p) {
      continue;
    }

    result = min(result, find(status | genStatus));
  }

  cout << (result == INF ? -1 : result) << "\n";

  return 0;
}