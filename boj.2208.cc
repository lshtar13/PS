#include <bits/stdc++.h>
#include <climits>

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
ll n, m, values[N + 1] = {}, preSum[N + 1] = {}, dp[N + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 1; i <= n; ++i) {
    cin >> values[i];
    preSum[i] = preSum[i - 1] + values[i];
  }

  dp[m] = preSum[m];
  ll result = dp[m];
  for (ll idx = m + 1; idx <= n; ++idx) {
    dp[idx] = dp[idx - 1] + values[idx];
    dp[idx] = max(dp[idx], preSum[idx] - preSum[idx - m]);
    result = max(dp[idx], result);
  }

  if (result > 0) {
    cout << result << "\n";
  } else {
    cout << 0 << "\n";
  }

  return 0;
}