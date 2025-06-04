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

cll N = 1e6;
ll n, segs[10 * N] = {};

ll query(ll node, ll st, ll en, ll num) {
  --segs[node];
  if (st == en) {
    return st;
  }

  ll mid = (st + en) / 2, left = segs[node * 2], right = segs[node * 2];
  if (num > left) {
    return query(node * 2 + 1, mid + 1, en, num - left);
  } else {
    return query(node * 2, st, mid, num);
  }
}

ll update(ll node, ll st, ll en, cll num, cll amt) {
  if (num < st || num > en) {
    return segs[node];
  } else if (st == en) {
    return segs[node] += amt;
  }

  ll mid = (st + en) / 2;
  return segs[node] = update(node * 2, st, mid, num, amt) +
                      update(node * 2 + 1, mid + 1, en, num, amt);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0, a, b, c; i < n; ++i) {
    cin >> a >> b;
    if (a == 1) {
      ll idx = query(1, 1, N, b);
      cout << idx << "\n";
    } else if (a == 2) {
      cin >> c;
      update(1, 1, N, b, c);
    }
  }

  return 0;
}