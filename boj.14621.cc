#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <tuple>

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

cll N = 1000, M = 10000;
ll n, m, parent[N] = {};
bool isMale[N] = {};
priority_queue<info_t, vector<info_t>, greater<info_t>> pq;

ll find(ll node) {
  return parent[node] = parent[node] == node ? node : find(parent[node]);
}

void merge(ll u, ll v) { parent[find(u)] = find(v); }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (ll i = 0; i < n; ++i) {
    cin.ignore(1);
    char c;
    cin >> c;
    isMale[i + 1] = c == 'M';
    parent[i + 1] = i + 1;
  }

  for (ll u, v, d, i = 0; i < m; ++i) {
    cin >> u >> v >> d;
    pq.push(make_tuple(d, u, v));
  }

  ll result = 0, resultN = 0;
  while (!pq.empty()) {
    ll u, v, d;
    tie(d, u, v) = pq.top();
    pq.pop();

    if (!(isMale[u] ^ isMale[v]) || find(u) == find(v)) {
      continue;
    }

    merge(u, v);
    result += d, ++resultN;
  }

  cout << (resultN == n - 1 ? result : -1) << "\n";

  return 0;
}