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
cll N = 250, TIME = 250 * N + 1;
ll n, times[N + 1][2], dp[N + 1][TIME] = {{}};
// a가 time일때, 가장 차이 안나는 b의 시간

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[0][0] = 0;

  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> times[i][0] >> times[i][1];
    dp[0][0] += times[i][1];
  }

  for (ll a, b, i = 1; i <= n; ++i) {
    a = times[i][0], b = times[i][1];
    for (ll t = 0; t < TIME; ++t) {
      if (t >= a) {
        if (max(t, dp[i - 1][t]) > max(t, dp[i - 1][t - a] - b)) {
          dp[i][t] = dp[i - 1][t - a] - b;
        } else {
          dp[i][t] = dp[i - 1][t];
        }
      } else {
        dp[i][t] = dp[i - 1][t];
      }
    }
  }

  ll result = TIME;
  for (ll i = 0; i <= n; ++i) {
    for (ll t = 0; t < TIME; ++t) {
      result = min(result, max(t, dp[i][t]));
    }
  }

  cout << result << "\n";

  return 0;
}