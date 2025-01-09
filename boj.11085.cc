#include <bits/stdc++.h>
#include <climits>

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

cll P = 1000, W = 50000;
ll p, w, c, v, parents[P] = {};
vvpll mat(P);

ll findParent(ll node) {
  if (node == parents[node]) {
    return node;
  }

  return parents[node] = findParent(parents[node]);
}

inline void merge(ll n0, ll n1) { parents[n1] = findParent(n0); }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> p >> w >> c >> v;
  for (ll i = 0; i < p; ++i) {
    parents[i] = i;
  }

  for (ll n0, n1, width, i = 0; i < w; ++i) {
    cin >> n0 >> n1 >> width;
    mat[n0].emplace_back(make_pair(n1, width));
    mat[n1].emplace_back(make_pair(n0, width));
  }

  pqpll pq;
  for (auto &p : mat[c]) {
    pq.push(make_pair(p.second, p.first));
  }

  ll result = LLONG_MAX;
  while (findParent(c) != findParent(v)) {
    ll width = pq.top().first, node = pq.top().second;
    pq.pop();

    if (findParent(c) == findParent(node)) {
      continue;
    }

    result = min(result, width);
    merge(c, node);

    for (auto &p : mat[node]) {
      pq.push(make_pair(p.second, p.first));
    }
  }

  cout << result << "\n";

  return 0;
}