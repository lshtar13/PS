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

cll N = 2e5, M = 2e5, C = N, Mod = 1e9 + 7;
ll n, m, c, parents[N] = {}, nchilds[N] = {}, idxs[N] = {}, idx = 0,
            segs[N * 15] = {};
vll edges[N], mems[C], queries[C];

void update(ll node, ll left, ll right, ll idx, ll amnt) {
  if (idx < left || idx > right) {
    return;
  }

  segs[node] += amnt, segs[node] %= Mod;
  if (left != right) {
    ll mid = (left + right) / 2;
    update(node * 2, left, mid, idx, amnt);
    update(node * 2 + 1, mid + 1, right, idx, amnt);
  }
}

ll seek(ll node, ll left, ll right, ll st, ll en) {
  if (en < left || st > right) {
    return 0;
  } else if (left >= st && right <= en) {
    return segs[node] % Mod;
  }

  ll mid = (left + right) / 2, lresult = seek(node * 2, left, mid, st, en),
     rresult = seek(node * 2 + 1, mid + 1, right, st, en);

  return (lresult + rresult) % Mod;
}

ll dfs(ll node) {
  idxs[node] = idx++;
  for (auto &child : edges[node]) {
    if (parents[child] != -1) {
      continue;
    }

    parents[child] = node, nchilds[node] += dfs(child) + 1;
  }

  return nchilds[node];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> c;
  FOR(node, 0, n) {
    ll color;
    cin >> color;
    mems[--color].emplace_back(node);
  }
  FOR(edge, 0, n - 1) {
    ll a, b;
    cin >> a >> b;
    --a, --b;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
  }

  memset(parents, -1, sizeof(parents));
  parents[0] = 0;
  dfs(0);

  FOR(query, 0, m) {
    ll v, c;
    cin >> v >> c;
    --v, --c;
    queries[c].emplace_back(v);
  }

  ll result = 0;
  FOR(color, 0, c) {
    for (auto &mem : mems[color]) {
      update(1, 0, n - 1, idxs[mem], 1);
    }

    for (auto &v : queries[color]) {
      ll st = idxs[v], en = idxs[v] + nchilds[v],
         cur = seek(1, 0, n - 1, st, en);
      result = (result + cur) % Mod;
    }
  }

  cout << result << "\n";

  return 0;
}