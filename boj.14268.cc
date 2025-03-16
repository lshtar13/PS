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

cll N = 1e5, M = 1e5;
ll n, m, parents[N] = {}, numbering[N] = {}, nchild[N] = {}, segs[N * 15] = {};
vll childs[N];

void add(ll node, ll st, ll en, cll idx0, cll idx1, cll weight) {
  if (st > idx1 || en < idx0) {
    return;
  } else if (idx0 <= st && idx1 >= en) {
    segs[node] += weight;
    return;
  }

  ll mid = (st + en) / 2;
  add(node * 2, st, mid, idx0, idx1, weight);
  add(node * 2 + 1, mid + 1, en, idx0, idx1, weight);
}

ll find(ll node, ll st, ll en, cll idx) {
  if (st == en) {
    return segs[node];
  }

  ll mid = (st + en) / 2;
  if (idx <= mid) {
    return segs[node] + find(node * 2, st, mid, idx);
  } else {
    return segs[node] + find(node * 2 + 1, mid + 1, en, idx);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin >> parents[i];
    if (parents[i] != -1) {
      childs[--parents[i]].emplace_back(i);
    }
  }

  stack<ll> search, result;
  search.push(0);
  while (!search.empty()) {
    ll tgt = search.top();
    search.pop();

    result.push(tgt);
    for (auto child : childs[tgt]) {
      search.push(child);
    }
  }

  for (ll e, i = 0; i < n; ++i) {
    e = result.top();
    result.pop();

    numbering[e] = i;
    nchild[parents[e]] += nchild[e] + 1;
  }

  for (ll q = 0, c, i, w, idx; q < m; ++q) {
    cin >> c >> i;

    idx = numbering[--i];
    if (c == 1) {
      cin >> w;
      add(1, 0, n - 1, idx - nchild[i], idx, w);
    } else {
      cout << find(1, 0, n - 1, idx) << "\n";
    }
  }

  return 0;
}