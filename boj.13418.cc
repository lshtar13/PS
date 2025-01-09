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

cll N = 1000, M = 1e6;
ll n, m, parents0[N + 1] = {}, parents1[N + 1] = {};
priority_queue<pair<ll, pll>> edges0, edges1;

ll find(ll node, ll parent[]) {
  if (parent[node] == node) {
    return node;
  } else {
    return parent[node] = find(parent[node], parent);
  }
}

void merge(ll a, ll b, ll parent[]) {
  parent[find(a, parent)] = find(b, parent);
}

ll kruskal(ll parent[], priority_queue<pair<ll, pll>> &edges, ll weight) {
  ll result = 0;
  while (!edges.empty()) {
    ll a = edges.top().second.first, b = edges.top().second.second,
       c = edges.top().first * weight;
    edges.pop();

    if (find(a, parent) == find(b, parent)) {
      continue;
    }
    merge(a, b, parent);
    result += c;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll a, b, c, i = 0; i < m + 1; ++i) {
    cin >> a >> b >> c;
    c = 1 - c;
    edges0.push(make_pair(c, make_pair(a, b)));
    edges1.push(make_pair(-c, make_pair(a, b)));
  }

  for (ll i = 0; i <= n; ++i) {
    parents0[i] = i, parents1[i] = i;
  }

  ll worst = kruskal(parents0, edges0, 1);
  ll best = kruskal(parents1, edges1, -1);
  cout << worst * worst - best * best << "\n";

  return 0;
}