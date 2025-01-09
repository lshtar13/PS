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

cll N = 2000;
ll n;
vector<pair<pll, ll>> edges;
vvpll mat(N);

pll search(ll start, ll from, ll to) {
  ll tgt = start, tgtDist = 0;
  vll dist(n, -1);
  qll q;
  q.push(start);
  dist[start] = 0;
  while (!q.empty()) {
    ll node = q.front();
    q.pop();
    for (auto &p : mat[node]) {
      if (min(from, to) == min(p.first, node) &&
          max(from, to) == max(p.first, node)) {
        continue;
      }

      if (dist[p.first] != -1) {
        continue;
      }

      dist[p.first] = dist[node] + p.second;
      q.push(p.first);

      if (dist[p.first] > tgtDist) {
        tgt = p.first, tgtDist = dist[p.first];
      }
    }
  }

  return make_pair(tgt, tgtDist);
}

ll diameter(ll start, ll from, ll to) {
  return search(search(start, from, to).first, from, to).second;
}

ll find(ll from, ll to) {
  return diameter(from, from, to) + diameter(to, from, to);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll from, to, cost, i = 0; i < n - 1; ++i) {
    cin >> from >> to >> cost;

    mat[from].emplace_back(make_pair(to, cost));
    mat[to].emplace_back(make_pair(from, cost));
    edges.emplace_back(make_pair(make_pair(from, to), cost));
  }

  ll result = 0;
  for (auto &p : edges) {
    result = max(result, find(p.first.first, p.first.second) + p.second);
  }

  cout << result << "\n";

  return 0;
}