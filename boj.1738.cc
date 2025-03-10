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

cll N = 100, M = 2e4, W = 1e3, INF = (M)*W;
ll n, m;
vll dist(N, -INF - 1), prv(N, -1);
vpll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll u, v, w, i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    --u, --v;
    edges[u].emplace_back(make_pair(v, w));
  }

  dist[0] = 0;
  for (ll i = 0; i < n; ++i) {
    for (ll node = 0, dst, w; node < n; ++node) {
      if (dist[node] < -INF) {
        continue;
      }

      for (auto &p : edges[node]) {
        tie(dst, w) = p;
        if (w + dist[node] > dist[dst]) {
          dist[dst] = w + dist[node];
          prv[dst] = node;
          if (i == n - 1) {
            dist[dst] = INF;
          }
        }
      }
    }
  }

  if (abs(dist[n - 1]) >= INF) {
    cout << -1 << "\n";
  } else {
    stack<ll> s;
    for (ll node = n - 1; node >= 0; node = prv[node]) {
      s.push(node + 1);
    }

    while (!s.empty()) {
      cout << s.top() << " ";
      s.pop();
    }
    cout << "\n";
  }

END:

  return 0;
}