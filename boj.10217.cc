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

typedef tuple<int, int, int> info_t;
cll N = 100, M = 1e4, K = 1e4, D = 1e3, INF = D * K + 1;
ll t, n, m, k;
vector<info_t> edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t >> n >> m >> k;
  for (ll i = 0, u, v, c, d; i < k; ++i) {
    cin >> u >> v >> c >> d;
    --u, --v;
    edges[u].emplace_back(d, c, v);
  }

  for (ll i = 0; i < n; ++i) {
    sort(edges[i].begin(), edges[i].end());
  }

  int dists[M + 2][N] = {{}};
  memset(dists, 0x3f3f3f3f, sizeof(dists));

  priority_queue<info_t, vector<info_t>, greater<info_t>> pq;
  pq.push({0, 0, 0});
  for (int cost, node, dist; !pq.empty();) {
    tie(dist, cost, node) = pq.top();
    pq.pop();

    if (node == n - 1) {
      break;
    } else if (dist > dists[cost][node]) {
      continue;
    }

    int av, c, d, ncost, ndist;
    for (auto &info : edges[node]) {
      tie(d, c, av) = info;

      ncost = cost + c, ndist = dist + d;
      if (ncost > m) {
        continue;
      } else if (dists[ncost][av] > ndist) {
        dists[ncost][av] = ndist;
        pq.push({ndist, ncost, av});
      }
    }
  }

  int result = INF;
  for (ll i = 0; i <= m; ++i) {
    result = min(result, dists[i][n - 1]);
  }

  if (result == INF) {
    cout << "Poor KCM\n";
  } else {
    cout << result << "\n";
  }

  return 0;
}