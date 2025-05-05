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

cll N = 100, M = 100, S = 100, V = 100;
ll n, m, s, v, matched[M] = {};
vll edges[N];
double rats[N][2] = {{}}, tunnels[M][2] = {{}};

inline double calcDist(double x0, double y0, double x1, double y1) {
  double dx = abs(x0 - x1), dy = abs(y0 - y1);
  return sqrt(dx * dx + dy * dy);
}

bool dfs(ll rat, bool visited[]) {
  for (auto &tunnel : edges[rat]) {
    if (visited[tunnel]) {
      continue;
    }

    visited[tunnel] = true;
    if (matched[tunnel] == -1 || dfs(matched[tunnel], visited)) {
      matched[tunnel] = rat;
      return true;
    }
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> s >> v;
  for (ll i = 0; i < n; ++i) {
    cin >> rats[i][0] >> rats[i][1];
  }
  for (ll i = 0; i < m; ++i) {
    cin >> tunnels[i][0] >> tunnels[i][1];
  }

  for (ll rat = 0; rat < n; ++rat) {
    for (ll tunnel = 0; tunnel < m; ++tunnel) {
      double dist = calcDist(rats[rat][0], rats[rat][1], tunnels[tunnel][0],
                             tunnels[tunnel][1]);
      if (dist <= s * v) {
        edges[rat].emplace_back(tunnel);
      }
    }
  }

  // bipartite matching
  ll nmatched = 0;
  memset(matched, -1, sizeof(matched));
  for (ll rat = 0; rat < n; ++rat) {
    bool visited[M] = {};
    nmatched += dfs(rat, visited);
  }

  cout << n - nmatched << "\n";

  return 0;
}