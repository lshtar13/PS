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

typedef tuple<ll, ll, ll> info_t;

cll Book = 100, N = 100, M = 100, Node = N + M + 2, Src = 0, Snk = 1, INF = 1e9;
ll n, m, flows[Node][Node] = {{}}, caps[Node][Node] = {{}};
vpll edges[Node];
// bellman- ford

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll cust = 2; cust < n + 2; ++cust) {
    cin >> caps[cust][Snk];
    edges[Snk].emplace_back(cust, 0);
    edges[cust].emplace_back(Snk, 0);
  }
  for (ll store = n + 2; store < n + m + 2; ++store) {
    cin >> caps[Src][store];
    edges[store].emplace_back(Src, 0);
    edges[Src].emplace_back(store, 0);
  }
  for (ll store = n + 2; store < n + m + 2; ++store) {
    for (ll cost, cust = 2; cust < n + 2; ++cust) {
      cin >> cost;
      caps[store][cust] = Book;

      edges[cust].emplace_back(store, -cost);
      edges[store].emplace_back(cust, cost);
    }
  }

  ll result = 0;
  while (true) {
    ll dists[Node] = {}, prvs[Node] = {};
    bool inQueue[Node] = {};
    memset(dists, 0x3f3f3f3f, sizeof(dists));
    memset(prvs, -1, sizeof(prvs));

    qll q;
    q.push(Src);
    dists[Src] = 0, prvs[Src] = 0, inQueue[Src] = true;
    while (!q.empty()) {
      ll node = q.front();
      q.pop();
      inQueue[node] = false;

      for (auto &p : edges[node]) {
        ll av = p.first, cost = p.second;

        if (caps[node][av] - flows[node][av] > 0 &&
            dists[av] > dists[node] + cost) {
          dists[av] = dists[node] + cost;
          prvs[av] = node;

          if (!inQueue[av]) {
            q.push(av);
            inQueue[av] = true;
          }
        }
      }
    }

    if (prvs[Snk] == -1) {
      break;
    }

    ll flow = INF;
    for (ll node = Snk, prv = prvs[node]; node != Src;) {
      flow = min(flow, caps[prv][node] - flows[prv][node]);
      node = prv, prv = prvs[node];
    }

    for (ll node = Snk, prv = prvs[node]; node != Src;) {
      flows[prv][node] += flow, flows[node][prv] -= flow;
      node = prv, prv = prvs[node];
    }

    result += dists[Snk] * flow;
  }

  cout << result << "\n";

  return 0;
}