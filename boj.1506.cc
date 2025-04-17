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

cll N = 100, INF = 1e6 + 1;
ll n, costs[N] = {}, totalCost = 0;
bool mat[N][N] = {{}}, visited[N] = {};

stack<ll> s;
ll idx = 0, idxs[N] = {};

ll dfs(ll node) {
  if (idxs[node]) {
    return idxs[node];
  }

  ll genesis = idxs[node] = ++idx;
  s.push(node);
  for (ll av = 0; av < n; ++av) {
    if (!mat[node][av] || visited[av]) {
      continue;
    }

    idxs[node] = min(dfs(av), idxs[node]);
  }

  if (idxs[node] == genesis) {
    ll minCost = INF;
    while (!s.empty()) {
      ll tnode = s.top();
      s.pop();

      visited[tnode] = true, minCost = min(minCost, costs[tnode]);
      if (tnode == node) {
        break;
      }
    }

    totalCost += minCost;
  }

  return idxs[node];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (ll i = 0; i < n; ++i) {
    cin >> costs[i];
  }

  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < n; ++l) {
      char c;
      cin >> c;
      mat[i][l] = c - '0';
    }
  }

  for (ll node = 0; node < n; ++node) {
    if (!visited[node]) {
      dfs(node);
    }
  }
  cout << totalCost << "\n";

  return 0;
}