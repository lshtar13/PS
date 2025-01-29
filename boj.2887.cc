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

cll N = 1e5;
ll n, nincluded = 0, parents[N] = {};
bool included[N] = {};
pll cords[3][N];

ll find(ll node) {
  if (node == parents[node]) {
    return node;
  } else {
    return parents[node] = find(parents[node]);
  }
}

inline void unite(ll a, ll b) { parents[find(a)] = find(b); }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll x, y, z, i = 0; i < n; ++i) {
    cin >> x >> y >> z;
    cords[0][i] = {x, i}, cords[1][i] = {y, i}, cords[2][i] = {z, i};
    parents[i] = i;
  }

  ll dist, a, b;
  priority_queue<info_t, vector<info_t>, greater<info_t>> pq;
  for (ll c = 0; c < 3; ++c) {
    sort(cords[c], cords[c] + n);
    for (ll i = 0; i < n - 1; ++i) {
      a = cords[c][i].second, b = cords[c][i + 1].second,
      dist = abs(cords[c][i].first - cords[c][i + 1].first);
      pq.push(make_tuple(dist, a, b));
    }
  }

  ll result = 0;
  while (!pq.empty()) {
    tie(dist, a, b) = pq.top();
    pq.pop();

    if (find(a) == find(b)) {
      continue;
    }
    unite(a, b);
    result += dist;
  }

  cout << result << "\n";

  return 0;
}