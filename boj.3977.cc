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
ll n, m, cnt, cnts[N] = {}, degree[N] = {};
stack<ll> s;
bool finished[N] = {}, visited[N] = {}, isValid[N] = {};

ll scc(ll node, vvll &edges) {
  ll ret = cnts[node] = cnt++;
  visited[node] = true;
  s.push(node);
  for (auto &av : edges[node]) {
    if (!visited[av]) {
      ret = min(ret, scc(av, edges));
    } else if (!finished[av]) {
      ret = min(ret, cnts[av]);
    }
  }

  if (ret == cnts[node]) {
    isValid[ret] = true;
    while (true) {
      ll tnode = s.top();
      s.pop();

      finished[tnode] = true;
      cnts[tnode] = ret;
      if (tnode == node) {
        break;
      }
    }
  }

  return ret;
}

void solve() {
  cin >> n >> m;
  vvll edges(n), group(n);
  memset(finished, false, sizeof(finished));
  memset(visited, false, sizeof(visited));
  memset(isValid, false, sizeof(isValid));
  memset(cnts, 0, sizeof(cnts));
  memset(degree, 0, sizeof(degree));
  for (ll i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    edges[a].emplace_back(b);
  }

  // strongly connected components
  // topology-sort (use only degree)
  cnt = 0;
  for (ll node = 0; node < n; ++node) {
    if (!visited[node]) {
      scc(node, edges);
    }
  }

  for (ll a = 0; a < n; ++a) {
    for (auto &b : edges[a]) {
      if (cnts[a] != cnts[b]) {
        ++degree[cnts[b]];
      }
    }
  }

  ll nresult = 0, result = 0;
  for (ll i = 0; i < n; ++i) {
    if (isValid[i] && !degree[i]) {
      ++nresult, result = i;
    }
  }
  if (nresult != 1) {
    cout << "Confused\n";
  } else {
    for (ll i = 0; i < n; ++i) {
      if (cnts[i] == result) {
        cout << i << "\n";
      }
    }
  }
  cout << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}