#include <bits/stdc++.h>
#include <queue>
#include <utility>

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

cll N = 1e3, P = 1e4, K = N, PRICE = 1e6;
ll n, p, k;
vpll edges[N];

bool avail(ll limit) {
  ll costs[N] = {}, cost, node;
  memset(costs, 0x3f3f3f3f, sizeof(costs));

  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    tie(cost, node) = pq.top();
    pq.pop();

    if (costs[node] < cost) {
      continue;
    }

    ll av, price, newCost;
    for (auto &p : edges[node]) {
      tie(av, price) = p;
      newCost = cost + (price > limit);
      if (newCost < costs[av]) {
        pq.push({costs[av] = newCost, av});
      }
    }
  }

  return costs[n - 1] <= k;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> p >> k;
  for (ll a, b, price, i = 0; i < p; ++i) {
    cin >> a >> b >> price;
    --a, --b;
    edges[a].emplace_back(make_pair(b, price));
    edges[b].emplace_back(make_pair(a, price));
  }

  ll st = 0, en = PRICE, result = -1;
  while (st <= en) {
    ll mid = (st + en) / 2;

    if (avail(mid)) {
      result = mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  cout << result << '\n';

  return 0;
}