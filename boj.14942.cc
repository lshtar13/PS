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

cll N = 1e5, S = 15;
ll n, energy[N] = {}, depths[N] = {}, sums[N] = {}, sparse[S][N] = {{}},
      *parents = sparse[0];
vpll edges[N];

void findParent(ll node) {
  for (auto &p : edges[node]) {
    if (p.first == parents[node]) {
      continue;
    }

    sums[p.first] = sums[node] + p.second, parents[p.first] = node,
    depths[p.first] = depths[node] + 1;
    findParent(p.first);
  }
}

void fillSparse() {
  for (ll s = 1; s < S; ++s) {
    for (ll node = 0; node < n; ++node) {
      sparse[s][node] = sparse[s - 1][sparse[s - 1][node]];
    }
  }
}

ll query(ll node, ll amt) {
  for (ll s = 0; s < S; ++s) {
    if (amt & (1 << s)) {
      node = sparse[s][node];
    }
  }

  return node;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> energy[i];
  }
  for (ll a, b, c, i = 0; i < n - 1; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    edges[a].emplace_back(make_pair(b, c));
    edges[b].emplace_back(make_pair(a, c));
  }

  findParent(0);
  fillSparse();

  for (ll node = 0; node < n; ++node) {
    ll st = 0, en = depths[node], result;
    while (st <= en) {
      ll mid = (st + en) / 2, idx = query(node, mid);
      if (sums[node] - sums[idx] <= energy[node]) {
        st = mid + 1, result = idx;
      } else {
        en = mid - 1;
      }
    }

    cout << result + 1 << "\n";
  }

  return 0;
}