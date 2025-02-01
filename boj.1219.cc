#include <bits/stdc++.h>
#include <climits>
#include <tuple>

using namespace std;
typedef long long ll;
typedef const ll cll;
typedef vector<ll> vll;
typedef tuple<ll, ll, ll> info_t;

cll N = 100, M = 50, PRICE = 1e6, INF = -PRICE * N;
ll n, m, st, en, profits[N] = {}, deposit[N] = {};
bool avail[N] = {};
vector<info_t> edges;
vll mat[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(deposit, 0x5f5f5f5f, sizeof(deposit));

  cin >> n >> st >> en >> m;
  for (ll src, dst, price, i = 0; i < m; ++i) {
    cin >> src >> dst >> price;
    edges.emplace_back(make_tuple(src, dst, price));
    mat[src].emplace_back(dst);
  }
  for (ll i = 0; i < n; ++i) {
    cin >> profits[i];
  }

  deposit[st] = -profits[st];
  avail[st] = true;
  for (ll src, dst, price, newDeposit, v = 0; v < n - 1; ++v) {
    for (auto &edge : edges) {
      tie(src, dst, price) = edge;
      newDeposit = deposit[src] + price - profits[dst];
      if (avail[src] && deposit[dst] > newDeposit) {
        avail[dst] = avail[src];
        deposit[dst] = newDeposit;
      }
    }
  }

  if (!avail[en]) {
    cout << "gg\n";
    goto END;
  }

  for (ll src, dst, price, newDeposit, v = 0; v < n; ++v) {
    for (auto &edge : edges) {
      tie(src, dst, price) = edge;

      newDeposit = deposit[src] + price - profits[dst];
      if (avail[src] && deposit[dst] > newDeposit) {
        deposit[dst] = INF;
        if (dst == en) {
          cout << "Gee\n";
          goto END;
        }
      }
    }
  }

  cout << -deposit[en] << "\n";

END:

  return 0;
}