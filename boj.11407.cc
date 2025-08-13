#include <bits/stdc++.h>
#include <queue>

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

cll N = 100, M = 100, SRC = 0, SNK = 1, INF = 1e9;
ll n, m, cap[N + M + 2][N + M + 2] = {{}}, flow[N + M + 2][N + M + 2] = {{}},
                                costs[N + M + 2][N + M + 2] = {{}};

inline ll cust2idx(ll cust) { return cust + 2; };
inline ll store2idx(ll store) { return store + n + 2; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  FOR(cust, 0, n) { cin >> cap[SRC][cust2idx(cust)]; }
  FOR(store, 0, m) { cin >> cap[store2idx(store)][SNK]; }
  FOR(store, 0, m) FOR(cust, 0, n) {
    cin >> cap[cust2idx(cust)][store2idx(store)];
  }
  FOR(store, 0, m) FOR(cust, 0, n) {
    cin >> costs[cust2idx(cust)][store2idx(store)];
    costs[store2idx(store)][cust2idx(cust)] =
        -costs[cust2idx(cust)][store2idx(store)];
  }

  ll nBook = 0, dist = 0;
  while (true) {
    bool isInQ[N + M + 2] = {};
    ll dists[N + M + 2] = {}, prvs[N + M + 2];
    memset(dists, 0x3f3f3f3f, sizeof(dists));
    dists[SRC] = 0;

    qll q;
    q.push(SRC);
    isInQ[SRC] = true;
    while (!q.empty()) {
      ll node = q.front(), from, to;
      isInQ[node] = false;
      q.pop();

      FOR(av, 0, N + M + 2) {
        if (av == node || cap[node][av] - flow[node][av] <= 0) {
          continue;
        } else if (dists[node] + costs[node][av] >= dists[av]) {
          continue;
        }

        dists[av] = dists[node] + costs[node][av], prvs[av] = node;
        if (!isInQ[av]) {
          isInQ[av] = true;
          q.push(av);
        }
      }
    }

    if (dists[SNK] > INF) {
      break;
    }

    dist += dists[SNK], ++nBook;
    for (ll node = SNK; node != SRC; node = prvs[node]) {
      ++flow[prvs[node]][node], --flow[node][prvs[node]];
    }
  }

  cout << nBook << "\n" << dist << "\n";

  return 0;
}