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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 4e4, M = 1e4, Degree = 20;
ll n, m, parents[N][Degree] = {{}}, dists[N][Degree] = {{}}, depths[N] = {};
vpll edges[N];
bool checked[N] = {};

pll query(ll node, ll amnt) {
  ll dist = 0;
  for (ll i = 0; i < Degree; ++i) {
    if (amnt & (1 << i)) {
      dist += dists[node][i], node = parents[node][i];
    }
  }

  return {node, dist};
}

ll calcDist(ll a, ll b) {
  ll result;
  if (depths[a] < depths[b]) {
    tie(b, result) = query(b, depths[b] - depths[a]);
  } else {
    tie(a, result) = query(a, depths[a] - depths[b]);
  }
  if (a == b) {
    return result;
  }

  ll amnt = 1, parentA = a, parentB = b;
  for (ll i = Degree - 1; i >= 0; --i) {
    if (parents[parentA][i] != parents[parentB][i]) {
      parentA = parents[parentA][i], parentB = parents[parentB][i],
      amnt += (1 << i);
    }
  }
  result += query(a, amnt).second + query(b, amnt).second;

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n - 1) {
    ll a, b, dist;
    cin >> a >> b >> dist;
    --a, --b;
    edges[a].emplace_back(b, dist);
    edges[b].emplace_back(a, dist);
  }

  qll q;
  q.push(0);
  parents[0][0] = 0, dists[0][0] = 0, checked[0] = true;
  while (!q.empty()) {
    ll node = q.front();
    q.pop();

    for (auto &p : edges[node]) {
      ll av = p.first, dist = p.second;
      if (checked[av]) {
        continue;
      }

      parents[av][0] = node, dists[av][0] = dist, depths[av] = depths[node] + 1,
      checked[av] = true;
      q.push(av);
    }
  }

  for (ll degree = 1; degree < Degree; ++degree) {
    for (ll node = 0; node < n; ++node) {
      ll prv = parents[node][degree - 1];
      parents[node][degree] = parents[prv][degree - 1];
      dists[node][degree] = dists[node][degree - 1] + dists[prv][degree - 1];
    }
  }

  cin >> m;
  FOR(i, m) {
    ll a, b;
    cin >> a >> b;
    cout << calcDist(--a, --b) << "\n";
  }

  return 0;
}