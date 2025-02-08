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
ll pos[N + 1] = {}, seg[18 * N] = {};

ll update(ll node, ll left, ll right, cll idx, cll num) {
  if (idx < left || idx > right) {
    return seg[node];
  } else if (left == right) {
    return seg[node] = num;
  }

  ll mid = (left + right) / 2;
  return seg[node] = update(node * 2, left, mid, idx, num) +
                     update(node * 2 + 1, mid + 1, right, idx, num);
}

ll sum(ll node, ll left, ll right, cll st, cll en) {
  if (en < left || st > right) {
    return 0;
  } else if (st <= left && en >= right) {
    return seg[node];
  }

  ll mid = (left + right) / 2;
  return sum(node * 2, left, mid, st, en) +
         sum(node * 2 + 1, mid + 1, right, st, en);
}

void solve(void) {
  ll n, m, next, movie;
  cin >> n >> m;
  memset(seg, 0, sizeof(seg));

  for (ll i = 1; i <= n; ++i) {
    update(1, 1, n + m, pos[i] = i + m, 1);
  }

  next = m;
  for (ll q = 0; q < m; ++q) {
    cin >> movie;
    cout << sum(1, 1, n + m, 1, pos[movie] - 1) << " ";
    update(1, 1, n + m, pos[movie], 0);
    update(1, 1, n + m, pos[movie] = next--, 1);
  }

  cout << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}