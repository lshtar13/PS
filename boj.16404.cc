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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 1e5, M = 1e5;
ll n, m, nchilds[N] = {}, idxs[N] = {}, segs[N * 10] = {};
vll childs[N];

ll dfs(ll node) {
  static ll idx = -1;
  idxs[node] = ++idx;
  for (auto &child : childs[node]) {
    if (idxs[child] != -1) {
      continue;
    }

    nchilds[idxs[node]] += dfs(child) + 1;
  }

  return nchilds[idxs[node]];
}

void update(ll node, ll st, ll en, ll left, ll right, ll amnt) {
  if (right < st || left > en) {
    return;
  } else if (left <= st && right >= en) {
    segs[node] += amnt;
    return;
  }

  ll mid = (st + en) / 2;
  update(node * 2, st, mid, left, right, amnt);
  update(node * 2 + 1, mid + 1, en, left, right, amnt);
}

ll query(ll node, ll st, ll en, ll idx) {
  if (st == en) {
    return segs[node];
  }

  ll mid = (st + en) / 2;
  if (idx <= mid) {
    return segs[node] + query(node * 2, st, mid, idx);
  } else {
    return segs[node] + query(node * 2 + 1, mid + 1, en, idx);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  FOR(seller, 0, n) {
    ll parent;
    cin >> parent;
    if (parent > 0) {
      childs[--parent].emplace_back(seller);
    }
  }

  memset(idxs, -1, sizeof(idxs));
  dfs(0);

  FOR(cmd, 0, m) {
    ll q, i, w, idx;
    cin >> q >> i;
    idx = idxs[--i];
    if (q == 1) {
      cin >> w;
      update(1, 0, n - 1, idx, idx + nchilds[idx], w);
    } else {
      cout << query(1, 0, n - 1, idx) << "\n";
    }
  }

  return 0;
}