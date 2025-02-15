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

cll N = 2e6, X = 2e6;
ll n, segs[20 * X] = {};

ll add(ll node, ll st, ll en, ll idx) {
  if (idx < st || idx > en) {
    return segs[node];
  } else if (st == en) {
    return ++segs[node];
  }

  ll mid = (st + en) / 2;
  return segs[node] =
             add(node * 2, st, mid, idx) + add(node * 2 + 1, mid + 1, en, idx);
}

ll query(ll node, ll st, ll en, ll idx) {
  --segs[node];
  ll mid = (st + en) / 2, left = segs[node * 2], right = segs[node * 2 + 1];
  if (st == en) {
    return st;
  } else if (left < idx) {
    return query(node * 2 + 1, mid + 1, en, idx - left);
  } else {
    return query(node * 2, st, mid, idx);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll t, x, num, q = 0; q < n; ++q) {
    cin >> t >> x;
    if (t == 1) {
      add(1, 1, X, x);
    } else {
      num = query(1, 1, X, x);
      cout << num << '\n';
    }
  }

  return 0;
}
