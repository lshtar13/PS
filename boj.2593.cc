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

cll N = 1e5, M = 100;
ll n, m, a, b, prvs[M] = {}, checked[M] = {};
bool adjs[M][M] = {{}};
pll elevs[M];
vll dsts;
qll q;

bool isAdj(ll i, ll l) {
  ll x, y, nx, ny;
  tie(x, y) = elevs[i];
  tie(nx, ny) = elevs[l];

  for (ll v = y; v <= n; v += x) {
    ll nv = v - ny;
    if (nv >= 0 && nv % nx == 0) {
      return true;
    }
  }

  return false;
}

bool reachable(ll num, ll idx) {
  ll x, y;
  tie(x, y) = elevs[idx];
  ll v = num - y;
  return v >= 0 && v % x == 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    elevs[i] = {y, x};

    for (ll l = 0, na, nb; l < i; ++l) {
      adjs[i][l] = adjs[l][i] = isAdj(i, l);
    }
  }

  memset(prvs, -1, sizeof(prvs));
  cin >> a >> b;
  for (ll i = 0; i < m; ++i) {
    if (reachable(a, i)) {
      q.push(i);
      prvs[i] = i;
    }
  }

  if (q.empty()) {
    cout << -1 << "\n";
    return 0;
  }

  for (ll i = 0; i < m; ++i) {
    if (reachable(b, i)) {
      dsts.emplace_back(i);
    }
  }

  while (!q.empty()) {
    ll node = q.front();
    q.pop();

    for (ll av = 0; av < m; ++av) {
      if (!adjs[node][av] || prvs[av] != -1) {
        continue;
      }

      prvs[av] = node, checked[av] = checked[node] + 1;
      q.push(av);
    }
  }

  ll node = -1, cnt = M + 1;
  for (auto &dst : dsts) {
    if (cnt > checked[dst]) {
      node = dst, cnt = checked[dst];
    }
  }

  if (node == -1) {
    cout << -1 << "\n";
  } else {
    stack<ll> s;
    s.push(node);
    while (prvs[node] != node) {
      node = prvs[node];
      s.push(node);
    }

    cout << s.size() << "\n";
    while (!s.empty()) {
      cout << s.top() + 1 << "\n";
      s.pop();
    }
  }

  return 0;
}