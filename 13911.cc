#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <utility>

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

cll V = 1e4, E = 3e5, W = 1e4, X = 1e8, Y = 1e8;
ll v, e, m, x, s, y, dist[V + 3][3] = {{}};
vvpll edges(V + 3);

void dijkstra(ll type) {
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push(make_pair(0, type));
  dist[type][type] = 0;
  while (!pq.empty()) {
    ll node = pq.top().second, d = pq.top().first;
    pq.pop();

    if (dist[node][type] < d) {
      continue;
    }

    for (auto &p : edges[node]) {
      ll av = p.first, w = p.second;
      if (av < 2) {
        continue;
      } else if (dist[av][type] <= d + w) {
        continue;
      } else if (!type && x < d + w) {
        continue;
      } else if (type && y < d + w) {
        continue;
      }

      pq.push(make_pair(dist[av][type] = d + w, av));
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> v >> e;
  for (ll u, v, w, i = 0; i < e; ++i) {
    cin >> u >> v >> w;
    ++u, ++v;
    edges[u].emplace_back(make_pair(v, w));
    edges[v].emplace_back(make_pair(u, w));
  }

  cin >> m >> x;
  for (ll node, i = 0; i < m; ++i) {
    cin >> node;
    ++node;
    edges[0].emplace_back(make_pair(node, 0));
    edges[node].emplace_back(make_pair(0, 0));
    dist[node][2] = 1;
  }

  cin >> s >> y;
  for (ll node, i = 0; i < s; ++i) {
    cin >> node;
    ++node;
    edges[1].emplace_back(make_pair(node, 0));
    edges[node].emplace_back(make_pair(1, 0));
    dist[node][2] = 1;
  }

  for (ll node = 0; node <= v + 1; ++node) {
    dist[node][0] = dist[node][1] = 1e9;
  }

  dijkstra(0);
  dijkstra(1);

  ll result = 1e9;
  for (ll i = 2; i <= v + 1; ++i) {
    if (dist[i][2]) {
      continue;
    } else if (dist[i][0] > x) {
      continue;
    } else if (dist[i][1] > y) {
      continue;
    } else {
      result = min(result, dist[i][0] + dist[i][1]);
    }
  }

  if (result != 1e9) {
    cout << result << "\n";
  } else {
    cout << -1 << "\n";
  }

  return 0;
}