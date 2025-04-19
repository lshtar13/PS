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

cll N = 1000, M = 25e4, K = 100, MK = 3e6;
ll n, m, k;
vpll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for (ll a, b, c, i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    edges[a].emplace_back(b, c);
  }

  pqll dists[N];
  multiset<ll> exists[N];
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dists[0].push(0);
  pq.push({0, 0});
  for (ll node, dist; !pq.empty();) {
    tie(dist, node) = pq.top();
    pq.pop();

    if (dist > dists[node].top()) {
      continue;
    }

    for (auto &p : edges[node]) {
      ll av, w, ndist;
      tie(av, w) = p;
      ndist = dist + w;

      if (dists[av].size() < k) {
        dists[av].push(ndist);
        pq.push({ndist, av});
      } else if (dists[av].top() > ndist) {
        dists[av].pop();
        dists[av].push(ndist);
        pq.push({ndist, av});
      }
    }
  }

  for (ll node = 0; node < n; ++node) {
    if (dists[node].size() == k) {
      cout << dists[node].top() << "\n";
    } else {
      cout << "-1\n";
    }
  }

  return 0;
}