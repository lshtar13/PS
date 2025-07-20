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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)

cll V = 1e4, E = 1e5;
ll v, e, parents[V] = {}, orders[V] = {}, oidx = 0, root;
vll edges[V], results;
bool isCut[V] = {};

ll check(ll node) {
  ll order = orders[node] = oidx++, nchild = 0;
  for (auto &av : edges[node]) {
    if (orders[av] == -1) {
      ++nchild;
      ll corder = check(av);
      order = min(order, corder);
      if (node != root && corder >= orders[node]) {
        isCut[node] = true;
      }
    } else {
      order = min(order, orders[av]);
    }
  }

  if (root == node && nchild > 1) {
    isCut[node] = true;
  }

  return order;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> v >> e;
  FOR(i, 0, e) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
  }

  memset(orders, -1, sizeof(orders));
  FOR(node, 0, v) {
    if (orders[node] == -1) {
      root = node;
      check(node);
    }
  }

  vll result;
  FOR(node, 0, v) {
    if (isCut[node]) {
      result.emplace_back(node + 1);
    }
  }

  cout << result.size() << "\n";
  for (auto &mem : result) {
    cout << mem << " ";
  }
  cout << "\n";

  return 0;
}