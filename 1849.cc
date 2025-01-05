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

cll N = 1e5;
set<ll> rest;
ll n, seq[N] = {}, seg[10 * N] = {};

void modify(ll st, ll en, ll node, ll tgt, ll amount) {
  if (tgt < st || en < tgt) {
    return;
  }

  seg[node] += amount;
  if (st != en) {
    ll mid = (st + en) / 2;
    modify(st, mid, 2 * node, tgt, amount);
    modify(mid + 1, en, 2 * node + 1, tgt, amount);
  }
}

ll query(ll st, ll en, ll node, ll tgt) {
  ll mid = (st + en) / 2;
  ll cur = seg[node], left = seg[2 * node], right = seg[2 * node + 1];

  if (cur == tgt) {
    return en;
  } else if (left < tgt) {
    return query(mid + 1, en, 2 * node + 1, tgt - left);
  } else {
    return query(st, mid, 2 * node, tgt);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    modify(0, n, 1, i, 1);
    rest.insert(i - 1);
  }
  for (ll num, idx, _idx, i = 1; i <= n; ++i) {
    cin >> num;
    _idx = query(0, n, 1, num);
    idx = *rest.lower_bound(_idx);
    rest.erase(idx);
    seq[idx] = i;
    modify(0, n, 1, idx + 1, -1);
  }

  for (ll i = 0; i < n; ++i) {
    cout << seq[i] << "\n";
  }

  return 0;
}