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

cll N = 1000, M = N * (N - 1) / 2;
ll n, m, x, y, dists[N] = {}, prvs[N] = {};
vpll edges[N];

ll dijkstra(bool track) {
  memset(dists, 0x3f3f3f3f, sizeof(dists));
  priority_queue<pll, vpll, greater<pll>> pq;
  pq.push({dists[0] = 0, 0});
  for (ll node, dist; !pq.empty();) {
    tie(dist, node) = pq.top();
    pq.pop();

    if (dist > dists[node]) {
      continue;
    }

    for (auto &p : edges[node]) {
      ll av = p.first, ndist = dist + p.second;
      if (min(x, y) == min(av, node) && max(x, y) == max(av, node)) {
        continue;
      } else if (ndist < dists[av]) {
        if (track) {
          prvs[av] = node;
        }
        dists[av] = ndist;
        pq.push({dists[av] = ndist, av});
      }
    }
  }

  return dists[n - 1];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll x, y, z, i = 0; i < m; ++i) {
    cin >> x >> y >> z;
    --x, --y;
    edges[x].emplace_back(y, z);
    edges[y].emplace_back(x, z);
  }

  dijkstra(true);
  ll result = 0;
  for (ll node = n - 1, prv = prvs[node]; node != prv;
       node = prv, prv = prvs[node]) {
    x = node, y = prv;
    result = max(result, dijkstra(false));
  }

  cout << result << "\n";

  return 0;
}