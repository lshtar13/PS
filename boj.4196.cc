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

cll N = 1e5, M = 1e5;
ll n, m, parents[N], groups[N] = {}, gidx, pidx;
stack<ll> prvs;

ll dfs(ll node, vvll &edges) {
  if (parents[node] != -1) {
    return parents[node];
  }

  ll parent = parents[node] = pidx++;
  prvs.push(node);
  for (auto &av : edges[node]) {
    if (groups[av] != -1) {
      continue;
    }

    parents[node] = min(parents[node], dfs(av, edges));
  }

  for (ll prv; parents[node] == parent && !prvs.empty();) {
    prv = prvs.top();
    prvs.pop();

    groups[prv] = gidx;

    if (prv == node) {
      ++gidx;
      break;
    }
  }

  return parents[node];
}

ll solve() {
  cin >> n >> m;
  vvll edges(n);
  for (ll i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    edges[--x].emplace_back(--y);
  }

  gidx = 0, pidx = 0;
  memset(parents, -1, sizeof(parents));
  memset(groups, -1, sizeof(groups));
  for (ll i = 0; i < n; ++i) {
    if (groups[i] != -1) {
      continue;
    }

    dfs(i, edges);
  }

  set<pll> checked;
  vll degrees(gidx, 0);
  for (ll node = 0; node < n; ++node) {
    for (auto &av : edges[node]) {
      ll a = groups[node], b = groups[av];

      if (a == b) {
        continue;
      }

      if (checked.find({a, b}) == checked.end()) {
        checked.insert({a, b});
        ++degrees[b];
      }
    }
  }

  ll result = 0;
  for (ll i = 0; i < gidx; ++i) {
    if (!degrees[i]) {
      ++result;
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}