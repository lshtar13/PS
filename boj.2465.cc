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

cll N = 1e5, Height = 2e9;
ll n, heights[N] = {}, seq[N] = {}, segs[N * 10] = {}, pos[N] = {};

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

ll query(ll node, ll st, ll en, ll amnt) {
  if (st == en) {
    return st;
  }

  ll mid = (st + en) / 2;
  if (segs[node * 2] >= amnt) {
    return query(node * 2, st, mid, amnt);
  } else {
    return query(node * 2 + 1, mid + 1, en, amnt - segs[node * 2]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) { cin >> heights[i]; }
  FOR(i, n) { cin >> seq[i]; }
  FOR(i, n) { update(1, 0, n - 1, i, 1); }
  sort(heights, heights + n);

  for (ll i = n - 1, nsmaller, idx; i >= 0; --i) {
    idx = query(1, 0, n - 1, seq[i] + 1);
    update(1, 0, n - 1, idx, -1);
    pos[i] = heights[idx];
  }

  FOR(i, n) { cout << pos[i] << "\n"; }

  return 0;
}