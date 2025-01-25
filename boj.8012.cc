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

cll N = 3e4, M = 5e3, Q = 15;
ll n, m, depths[N] = {}, mat[N][Q] = {{}};
vvll edges;

void findDepth(ll node) {
  for (auto &av : edges[node]) {
    if (mat[node][0] == av) {
      continue;
    }

    mat[av][0] = node, depths[av] = depths[node] + 1;
    findDepth(av);
  }
}

ll query(ll node, ll nElevate) {
  for (ll q = 0; q < Q; ++q) {
    if (nElevate & (1 << q)) {
      node = mat[node][q];
    }
  }

  return node;
}

ll findDist(ll a, ll b) {
  ll st = 0, en = min(depths[a], depths[b]), depth;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if (query(a, depths[a] - mid) == query(b, depths[b] - mid)) {
      depth = mid, st = mid + 1;
    } else {
      en = mid - 1;
    }
  }

  return depths[a] - depth + depths[b] - depth;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  edges.resize(n);
  for (ll a, b, i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    --a, --b;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
  }

  findDepth(0);
  for (ll q = 1; q < Q; ++q) {
    for (ll node = 0; node < n; ++node) {
      mat[node][q] = mat[mat[node][q - 1]][q - 1];
    }
  }

  cin >> m;
  ll prv, cur, result = 0;
  cin >> prv;
  prv = 0;
  for (ll c = 1; c < m; ++c) {
    cin >> cur;
    --cur;
    result += findDist(prv, cur);
    prv = cur;
  }

  cout << result << "\n";

  return 0;
}