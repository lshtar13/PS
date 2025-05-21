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

cll N = 400, P = 1e4, SRC = 0, SNK = 1, INF = 1e5;
ll n, p, cap[N][N] = {{}}, flow[N][N] = {{}};
vll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 최대 유량 ...
  cin >> n >> p;
  for (ll i = 0, from, to; i < p; ++i) {
    cin >> from >> to;
    --from, --to;
    edges[from].emplace_back(to);
    edges[to].emplace_back(from);
    ++cap[from][to];
  }

  ll result = 0;
  while (true) {
    vll parents(n, -1);
    parents[SRC] = SRC;

    qll q;
    q.push(SRC);
    while (!q.empty()) {
      ll node = q.front();
      q.pop();

      for (auto &av : edges[node]) {
        if (parents[av] == -1 && cap[node][av] - flow[node][av] > 0) {
          parents[av] = node;
          q.push(av);
        }
      }
    }

    if (parents[SNK] == -1) {
      break;
    }

    ll cost = INF;
    for (ll node = SNK, parent; node != SRC; node = parent) {
      parent = parents[node];
      cost = min(cost, cap[parent][node] - flow[parent][node]);
    }
    result += cost;

    for (ll node = SNK, parent; node != SRC; node = parent) {
      parent = parents[node];
      flow[parent][node] += cost;
      flow[node][parent] -= cost;
    }
  }

  cout << result << "\n";

  return 0;
}