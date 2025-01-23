#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <vector>

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

cll N = 1e5, M = 2e5, D = 100, E = 100, INF = 0x3f3f3f3f3f3f3f3f;
ll n, m, d, e, heights[N] = {}, dists[2][N] = {{}};
vpll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> d >> e;
  for (ll i = 0; i < n; ++i) {
    cin >> heights[i];
  }
  for (ll a, b, d, i = 0; i < m; ++i) {
    cin >> a >> b >> d;
    --a, --b;
    if (a == b) {
      continue;
    }
    edges[a].emplace_back(make_pair(b, d));
    edges[b].emplace_back(make_pair(a, d));
  }

  memset(dists, 0x3f3f3f3f, sizeof(dists));
  for (ll idx = 0; idx < 2; ++idx) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    if (idx == 0) {
      dists[0][0] = 0;
      pq.push({0, 0});
    } else {
      dists[1][n - 1] = 0;
      pq.push({0, n - 1});
    }
    while (!pq.empty()) {
      ll node = pq.top().second, dist = pq.top().first;
      pq.pop();

      if (dist != dists[idx][node]) {
        continue;
      }

      for (auto &p : edges[node]) {
        ll av = p.first, d = p.second;
        if (heights[node] >= heights[av]) {
          continue;
        } else if (d + dist >= dists[idx][av]) {
          continue;
        }

        pq.push({dists[idx][av] = d + dist, av});
      }
    }
  }

  ll result = LLONG_MIN;
  for (ll node = 0; node < n; ++node) {
    if (dists[0][node] >= INF || dists[1][node] >= INF) {
      continue;
    }
    ll achieve = heights[node], hp = dists[0][node] + dists[1][node];
    result = max(result, achieve * e - hp * d);
  }

  if (result != LLONG_MIN) {
    cout << result << "\n";
  } else {
    cout << "Impossible\n";
  }

  return 0;
}