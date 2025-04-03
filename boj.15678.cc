#include <algorithm>
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

cll N = 1e5, D = N - 1, K = 1e9;
ll n, d, scores[N] = {}, dp[N] = {}, segs[N * 10] = {};

ll update(ll node, ll idx0, ll idx1, ll idx, ll num) {
  if (idx < idx0 || idx > idx1) {
    return segs[node];
  } else if (idx0 == idx1) {
    return segs[node] = num;
  }

  ll mid = (idx0 + idx1) / 2;
  return segs[node] = max(update(node * 2, idx0, mid, idx, num),
                          update(node * 2 + 1, mid + 1, idx1, idx, num));
}

ll query(ll node, ll idx0, ll idx1, ll st, ll en) {
  if (en < idx0 || st > idx1) {
    return -K - 1;
  } else if (st <= idx0 && en >= idx1) {
    return segs[node];
  }

  ll mid = (idx0 + idx1) / 2;
  return max(query(node * 2, idx0, mid, st, en),
             query(node * 2 + 1, mid + 1, idx1, st, en));
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> d;
  for (ll i = 0; i < n; ++i) {
    cin >> scores[i];
  }

  memset(segs, 0xcfcfcfcf, sizeof(segs));

  ll result = -K - 1;
  dp[n - 1] = scores[n - 1];
  update(1, 0, n - 1, n - 1, dp[n - 1]);
  for (ll i = n - 2; i >= 0; --i) {
    dp[i] = scores[i];
    dp[i] += max(ll(0), query(1, 0, n - 1, i + 1, min(n - 1, i + d)));
    update(1, 0, n - 1, i, dp[i]);
  }

  cout << query(1, 0, n - 1, 0, n - 1) << "\n";

  return 0;
}