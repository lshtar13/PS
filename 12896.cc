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

cll N = 1e5;
ll n;
vvll edges(N);

pll find(ll start) {
  vll dist(n, -1);
  qll q;
  pll result(0, start);
  q.push(start);
  dist[start] = 0;
  while (!q.empty()) {
    ll node = q.front();
    q.pop();
    for (auto av : edges[node]) {
      if (dist[av] != -1) {
        continue;
      }

      q.push(av);
      dist[av] = dist[node] + 1;

      if (dist[av] > result.first) {
        result = make_pair(dist[av], av);
      }
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll u, v, i = 0; i < n - 1; ++i) {
    cin >> u >> v;
    --u, --v;

    edges[u].emplace_back(v);
    edges[v].emplace_back(u);
  }

  pll uInfo = find(0);
  ll u = uInfo.second, distU = uInfo.first;
  pll vInfo = find(u);
  ll v = vInfo.second, distV = vInfo.first;

  cout << distV / 2 + distV % 2 << "\n";

  return 0;
}