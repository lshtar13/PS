#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <tuple>
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

cll N = 1e4, P = 1e5;
ll n, p, taxs[N] = {};
vpll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> p;
  for (ll i = 0; i < n; ++i) {
    cin >> taxs[i];
  }
  for (ll s, e, l, i = 0; i < p; ++i) {
    cin >> s >> e >> l;
    --s, --e;
    edges[s].emplace_back(make_pair(e, l));
    edges[e].emplace_back(make_pair(s, l));
  }

  ll st = min_element(taxs, taxs + n) - taxs, cost = taxs[st];
  bool included[N] = {};
  included[st] = true;
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  for (auto &p : edges[st]) {
    pq.push(make_pair(taxs[p.first] + taxs[st] + p.second * 2, p.first));
  }

  for (ll added, to; !pq.empty();) {
    tie(added, to) = pq.top();
    pq.pop();

    if (included[to]) {
      continue;
    }

    cost += added;
    included[to] = true;
    for (auto &p : edges[to]) {
      if (!included[p.first]) {
        pq.push(make_pair(taxs[p.first] + taxs[to] + p.second * 2, p.first));
      }
    }
  }

  cout << cost << "\n";

  return 0;
}