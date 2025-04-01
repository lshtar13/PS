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
cll N = 1e5, M = 1e5, Parent = 0, Weight = 1;
ll n, m, unionFind[N][2] = {}; // parent, weight(prefixSum)

ll findParents(ll node) {
  ll parent = unionFind[node][Parent], pWeight, nparent;
  if (parent == node) {
    return node;
  }

  pWeight = unionFind[parent][Weight], nparent = findParents(parent);
  if (nparent != parent) {
    unionFind[node][Weight] += unionFind[parent][Weight];
  }

  return unionFind[node][Parent] = nparent;
}

void merge(ll a, ll b, ll w) {
  ll aParent = findParents(a), bParent = findParents(b);
  if (aParent == bParent) {
    return;
  }

  unionFind[bParent][Parent] = aParent;
  unionFind[bParent][Weight] = w - unionFind[b][Weight] + unionFind[a][Weight];
}

void solve() {
  memset(unionFind, 0, sizeof(unionFind));
  for (ll i = 0; i < n; ++i) {
    unionFind[i][Parent] = i;
  }

  cin.ignore();
  for (ll i = 0; i < m; ++i) {
    char q;
    ll a, b, w;
    cin >> q >> a >> b;
    --a, --b;
    if (q == '!') {
      cin >> w;
      merge(a, b, w);
    } else if (findParents(a) != findParents(b)) {
      cout << "UNKNOWN\n";
    } else {
      cout << unionFind[b][Weight] - unionFind[a][Weight] << "\n";
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n >> m && n && m) {
    solve();
  }

  return 0;
}