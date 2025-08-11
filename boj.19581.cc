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
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 1e5;
ll n;
vpll edges[N];
bool visited[4][N] = {{}};

pll dfs(ll node, bool visited[N]) {
  pll result(0, node);
  visited[node] = true;
  for (auto &p : edges[node]) {
    ll av = p.first, w = p.second;
    if (visited[av]) {
      continue;
    }

    pll nresult = dfs(av, visited);
    nresult.first += w;
    result = max(result, nresult);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(e, 0, n - 1) {
    ll a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    edges[a].emplace_back(b, w);
    edges[b].emplace_back(a, w);
  }

  ll end0, end1, end, diameter, result = 0;
  tie(diameter, end0) = dfs(0, visited[0]);
  tie(diameter, end1) = dfs(end0, visited[1]);

  visited[2][end1] = true;
  tie(diameter, end) = dfs(end0, visited[2]);
  result = max(result, diameter);

  visited[3][end0] = true;
  tie(diameter, end) = dfs(end1, visited[3]);
  result = max(result, diameter);

  cout << result << "\n";

  return 0;
}