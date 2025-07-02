#include <bits/stdc++.h>
#include <vector>

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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 500, M = 1e4, P = 1e3;
ll n, m, s, d, dists[N];
vll prvs[N];
bool checked[N], isBanned[N][N];
vpll edges[N];

void djikstra() {
  memset(dists, 0x3f3f3f3f, sizeof(dists));
  FOR(i, n) { prvs[i].clear(); }

  pqpll pq;
  pq.push({dists[s] = 0, s});
  while (!pq.empty()) {
    ll cost = -pq.top().first, node = pq.top().second;
    pq.pop();

    for (auto &p : edges[node]) {
      ll av = p.first, ncost = cost + p.second;
      if (isBanned[node][av]) {
        continue;
      } else if (dists[av] > ncost) {
        dists[av] = ncost;
        prvs[av].clear();
        prvs[av].emplace_back(node);
        pq.push({-ncost, av});
      } else if (dists[av] == ncost) {
        prvs[av].emplace_back(node);
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> n >> m;
    if (!n && !m) {
      break;
    } else {
      FOR(i, n) { edges[i].clear(); }
      memset(checked, false, sizeof(checked));
      memset(isBanned, false, sizeof(isBanned));
    }

    cin >> s >> d;
    FOR(i, m) {
      ll u, v, p;
      cin >> u >> v >> p;
      edges[u].emplace_back(v, p);
    }

    djikstra();
    if (dists[d] > P * M) {
      cout << "-1\n";
      continue;
    }

    qll q({d});
    checked[d] = true;
    while (!q.empty()) {
      ll node = q.front();
      q.pop();

      for (auto &prv : prvs[node]) {
        isBanned[prv][node] = true;
        if (!checked[prv]) {
          checked[prv] = true;
          q.push(prv);
        }
      }
    }

    djikstra();
    if (dists[d] > P * M) {
      cout << "-1\n";
      continue;
    } else {
      cout << dists[d] << "\n";
    }
  }

  return 0;
}