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

cll N = 5e5, M = 1e4;
ll n, m, segs[N * 10] = {};

ll update(ll node, ll idx0, ll idx1, ll idx, ll num) {
  if (idx < idx0 || idx > idx1) {
    return segs[node];
  } else if (idx0 == idx1) {
    return segs[node] += num;
  }

  ll mid = (idx0 + idx1) / 2;
  return segs[node] = update(node * 2, idx0, mid, idx, num) +
                      update(node * 2 + 1, mid + 1, idx1, idx, num);
}

ll query(ll node, ll idx0, ll idx1, ll st, ll en) {
  if (en < idx0 || st > idx1) {
    return 0;
  } else if (st <= idx0 && en >= idx1) {
    return segs[node];
  }

  ll mid = (idx0 + idx1) / 2;
  return query(node * 2, idx0, mid, st, en) +
         query(node * 2 + 1, mid + 1, idx1, st, en);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll idx = 0, num; idx < n; ++idx) {
    cin >> num;
    update(1, 0, n - 1, idx, num);
  }

  cin >> m;
  for (ll i = 0, q, idx, a; i < m; ++i) {
    cin >> q >> idx;
    if (q == 1) {
      cin >> a;
      update(1, 0, n - 1, idx - 1, a);
    } else {
      ll st = 0, en = n - 1, ans;
      while (st <= en) {
        ll mid = (st + en) / 2;
        if (query(1, 0, n - 1, 0, mid) >= idx) {
          ans = mid, en = mid - 1;
        } else {
          st = mid + 1;
        }
      }

      cout << ans + 1 << "\n";
    }
  }

  return 0;
}