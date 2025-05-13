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

cll N = 1e5, TERM = 1e6;
ll n, term, dp[N][2] = {};
pll sticks[N];
map<ll, ll> remains[2];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> term;
  for (ll i = 0, t, d; i < n; ++i) {
    cin >> t >> d;
    sticks[i] = {t, d};
  }
  sort(sticks, sticks + n);

  ll result = 0;
  for (ll i = 0, t, d, len; i < n; ++i) {
    tie(t, d) = sticks[i];
    dp[i][0] = dp[i][1] = len = abs(t - d) + term;

    dp[i][1] = max(dp[i][1], remains[0][t] + len);
    dp[i][0] = max(dp[i][0], remains[1][d] + len);

    remains[0][t] = max(remains[0][t], dp[i][0]);
    remains[1][d] = max(remains[1][d], dp[i][1]);

    result = max(result, dp[i][0]);
    result = max(result, dp[i][1]);
  }

  cout << result << "\n";

  return 0;
}