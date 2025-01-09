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

cll N = 300, M = 20;
ll n, m, benefits[M][N + 1] = {{}}, dp[2][N + 1] = {{}},
                         equities[M][N + 1] = {{}}, prvs[M][N + 1] = {{}};
// i까지 고려했을 때, N만큼의 금액을 쓰는 경우 ...

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll invest, i = 0; i < n; ++i) {
    cin >> invest;
    for (ll company = 0; company < m; ++company) {
      cin >> benefits[company][invest];
    }
  }

  for (ll cur, prv, c = 0; c < m; ++c) {
    cur = c % 2, prv = (c + 1) % 2;
    for (ll total = 0; total <= n; ++total) {
      dp[cur][total] = dp[prv][total], equities[c][total] = 0,
      prvs[c][total] = total;
      for (ll invst = 0; invst <= total; ++invst) {
        if (dp[cur][total] < dp[prv][total - invst] + benefits[c][invst]) {
          dp[cur][total] = dp[prv][total - invst] + benefits[c][invst];
          equities[c][total] = invst;
          prvs[c][total] = total - invst;
        }
      }
    }
  }

  cout << dp[(m - 1) % 2][n] << "\n";

  deque<ll> v;
  for (ll total = n, c = m - 1; c >= 0; --c) {
    v.emplace_front(equities[c][total]);
    total = prvs[c][total];
  }

  for (auto &_v : v) {
    cout << _v << " ";
  }
  cout << "\n";

  return 0;
}