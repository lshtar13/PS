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
ll n, m, groups[N] = {}, parents[N] = {}, pidx = 0, gidx = 0;
vll edges[N];
bool degrees[N] = {};

ll dfs(ll node) {
  if (parents[node] != -1) {
    return parents[node];
  }

  static stack<ll> s;
  s.push(node);
  ll parent = parents[node] = pidx++;
  for (auto &av : edges[node]) {
    if (groups[av] == -1) {
      parents[node] = min(parents[node], dfs(av));
    }
  }

  while (parent == parents[node] && !s.empty()) {
    ll mem = s.top();
    s.pop();

    groups[mem] = gidx;
    if (mem == node) {
      ++gidx;
      break;
    }
  }

  return parents[node];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    edges[a].emplace_back(b);
  }
  memset(groups, -1, sizeof(groups));
  memset(parents, -1, sizeof(parents));

  for (ll node = 0; node < n; ++node) {
    dfs(node);
  }

  ll result = gidx;
  for (ll node = 0; node < n; ++node) {
    for (auto &av : edges[node]) {
      if (groups[node] == groups[av]) {
        continue;
      }

      if (!degrees[groups[av]]) {
        --result, degrees[groups[av]] = true;
      }
    }
  }

  cout << result << "\n";

  return 0;
}