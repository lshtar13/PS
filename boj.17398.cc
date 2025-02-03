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

cll N = 1e5 + 10, M = 1e5 + 10, Q = M;
ll n, m, q, edges[M][2] = {{}}, toRemove[Q] = {}, parents[N] = {},
            nNodes[N] = {};
bool isToRemove[Q] = {};

ll findParent(ll node) {
  if (node == parents[node]) {
    return node;
  } else {
    return parents[node] = findParent(parents[node]);
  }
}

void merge(ll a, ll b) {
  a = findParent(a);
  b = findParent(b);
  if (a != b) {
    if (nNodes[a] < nNodes[b])
      swap(a, b);
    parents[b] = a;
    nNodes[a] += nNodes[b];
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> q;
  for (ll i = 0; i < n; ++i) {
    parents[i] = i, nNodes[i] = 1;
  }
  for (ll i = 0; i < m; ++i) {
    cin >> edges[i][0] >> edges[i][1];
    --edges[i][0], --edges[i][1];
  }

  for (ll i = 0; i < q; ++i) {
    cin >> toRemove[i];
    isToRemove[--toRemove[i]] = true;
  }

  for (ll a, b, i = 0; i < m; ++i) {
    if (!isToRemove[i]) {
      merge(edges[i][0], edges[i][1]);
    }
  }

  ll result = 0;
  for (ll edge, a, b, i = q - 1; i >= 0; --i) {
    edge = toRemove[i];
    a = findParent(edges[edge][0]), b = findParent(edges[edge][1]);
    if (a == b) {
      continue;
    }
    result += 1LL * nNodes[edges[edge][0]] * nNodes[edges[edge][1]];
    merge(a, b);
  }

  cout << result << "\n";

  return 0;
}