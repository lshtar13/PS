#include <bits/stdc++.h>
#include <queue>

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

typedef tuple<ll, ll, ll> info_t;

cll N = 1e4, M = 5e4, K = 20;
ll n, m, k, dists[N][K + 1] = {{}};
vpll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for (ll a, b, w, i = 0; i < m; ++i) {
    cin >> a >> b >> w;
    --a, --b;
    edges[a].push_back({b, w});
    edges[b].push_back({a, w});
  }

  memset(dists, 0x3f3f3f3f, sizeof(dists));
  priority_queue<info_t, vector<info_t>, greater<info_t>> pq;
  for (ll i = 0; i <= k; ++i) {
    dists[0][i] = 0;
  }

  pq.push({0, 0, 0});

  ll dist, pave, node, ndist, npave, av;
  while (!pq.empty()) {
    tie(dist, pave, node) = pq.top();
    pq.pop();

    if (dists[node][pave] < dist) {
      continue;
    }

    for (auto &p : edges[node]) {
      av = p.first, ndist = dist + p.second, npave = pave + 1;
      if (npave <= k && dist < dists[av][npave]) {
        pq.push({dists[av][npave] = dist, npave, av});
      }

      if (ndist < dists[av][pave]) {
        pq.push({dists[av][pave] = ndist, pave, av});
      }
    }
  }

  ll result = dists[n - 1][0];
  for (ll i = 1; i <= k; ++i) {
    result = min(result, dists[n - 1][i]);
  }

  cout << result << "\n";

  return 0;
}