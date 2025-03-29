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

cll L = 20, R = 20, N = 20;
ll n, l, r, dp[L][R][N + 1] = {{{}}};

ll fillDP(ll left, ll right, ll num) {
  if (left < 0 || right < 0) {
    return 0;
  } else if (dp[left][right][num] != -1) {
    return dp[left][right][num];
  }
  ll &result = dp[left][right][num];
  result = 0;

  if (!num && (right || left)) {
    return result = 0;
  }

  result += fillDP(left - 1, right, num - 1);
  result += fillDP(left, right - 1, num - 1);
  result += fillDP(left, right, num - 1) * (n - num - 1);

  return result;
}

ll solve() {
  cin >> n >> l >> r;
  return fillDP(l - 1, r - 1, n - 1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    dp[0][0][0] = 1;
    cout << solve() << "\n";
  }

  return 0;
}