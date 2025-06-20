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

cll N = 2e5, C = N, Q = 2e5;
ll n, c, nq, idx = 0, depths[N] = {}, nchilds[N] = {}, idxs[N] = {},
             segs[N * 15] = {};
vll edges[N];

ll dfs(ll node) {
  ll &nchild = nchilds[node] = 0;
  idxs[node] = idx++;
  for (auto &av : edges[node]) {
    if (!depths[av]) {
      depths[av] = depths[node] + 1;
      nchild += dfs(av) + 1;
    }
  }

  return nchild;
}

void update(ll node, ll st, ll en, ll idx, ll amnt) {
  if (idx < st || idx > en) {
    return;
  }

  segs[node] += amnt;
  if (st == en) {
    return;
  }

  ll mid = (st + en) / 2;
  if (idx <= mid) {
    update(node * 2, st, mid, idx, amnt);
  } else {
    update(node * 2 + 1, mid + 1, en, idx, amnt);
  }
}

ll query(ll node, ll st, ll en, ll from, ll to) {
  if (to < st || from > en) {
    return 0;
  } else if (st >= from && en <= to) {
    return segs[node];
  }

  ll mid = (st + en) / 2;
  return query(node * 2, st, mid, from, to) +
         query(node * 2 + 1, mid + 1, en, from, to);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> c;
  FOR(i, n - 1) {
    ll x, y;
    cin >> x >> y;
    --x, --y;
    edges[x].emplace_back(y);
    edges[y].emplace_back(x);
  }

  depths[--c] = 1;
  dfs(c);

  cin >> nq;
  FOR(i, nq) {
    ll q, a;
    cin >> q >> a;
    --a;
    if (q == 1) {
      update(1, 0, n - 1, idxs[a], 1);
    } else {
      cout << (depths[a] * query(1, 0, n - 1, idxs[a], idxs[a] + nchilds[a]))
           << "\n";
    }
  }

  return 0;
}