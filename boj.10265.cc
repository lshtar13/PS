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

cll N = 1000, K = 1000, X = N;
ll n, k, parents[N] = {}, pidx = 0, groups[N] = {}, gidx = 0, degrees[N] = {},
         sizes[N + 1] = {}, components[N + 1][2] = {{}}, cidx = 0,
         dp[K + 1][K + 1] = {{}};
bool checked[N] = {}, results[N + 1] = {};
deque<deque<ll>> sccs;
vll companions[N], childs[N + 1], starts;

ll check0(ll node) {
  if (parents[node] != -1) {
    return parents[node];
  }

  static stack<ll> s;
  s.push(node);
  ll parent = parents[node] = pidx++;

  static bool checked[N] = {};
  for (auto &companion : companions[node]) {
    if (!checked[companion]) {
      parents[node] = min(parents[node], check0(companion));
    }
  }

  if (parent == parents[node]) {
    deque<ll> scc;
    while (!s.empty()) {
      ll pnode = s.top();
      scc.push_back(pnode);
      s.pop();

      checked[pnode] = true;
      groups[pnode] = gidx;

      if (pnode == node) {
        break;
      }
    }

    ++gidx;
    sccs.emplace_back(scc);
  }

  return parents[node];
}

ll check1(ll group) {
  for (auto &mem : sccs[group]) {
    for (auto &companion : companions[mem]) {
      if (groups[companion] != group && !checked[groups[companion]]) {
        checked[groups[companion]] = true;
        childs[group].emplace_back(groups[companion]);
      }
    }
  }

  return sccs[group].size();
}

ll check2(ll group) {
  ll result = 1;
  for (auto &child : childs[group]) {
    result += check2(group);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  FOR(a, 0, n) {
    ll b;
    cin >> b;
    companions[--b].emplace_back(a);
  }

  // find scc
  memset(parents, -1, sizeof(parents));
  FOR(node, 0, n) {
    if (!checked[node]) {
      check0(node);
    }
  }

  // make tree
  memset(checked, 0, sizeof(checked));
  FOR(group, 0, gidx) { sizes[group] = check1(group); }
  FOR(group, 0, gidx) {
    if (!checked[group]) {
      components[cidx][0] = sizes[group], components[cidx][1] = check2(group),
      ++cidx;
    }
  }

  FOR(size, components[0][0], k + 1) {
    dp[0][size] = min(size, components[0][1]);
  }
  FOR(group, 1, gidx)
  FOR(limit, 0, k)
  FOR(size, components[group][0], min(limit, components[group][1]) + 1) {
    dp[group][limit] =
        max(dp[group][limit], dp[group - 1][limit - size] + size);
  }

  cout << dp[gidx - 1][k] << "\n";

  return 0;
}