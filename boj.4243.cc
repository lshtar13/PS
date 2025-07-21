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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 100, Dur = 15e6;
ll n, st, dur[N], dp[N][N][2];

ll solve() {
  cin >> n >> st;
  --st, dur[0] = 0;
  FOR(pos, 1, n) {
    cin >> dur[pos];
    dur[pos] += dur[pos - 1];
  }

  memset(dp, 0x3f3f3f3f, sizeof(dp));
  dp[st][st][0] = dp[st][st][1] = 0;
  IFOR(left, st, 0) FOR(right, st, n) {
    ll nleft = n - (right - left), &value0 = dp[left][right][0],
       &value1 = dp[left][right][1];
    if (left < right) {
      value0 = min(value0, dp[left + 1][right][0] +
                               (dur[left + 1] - dur[left]) * nleft);
      value0 = min(value0,
                   dp[left + 1][right][1] + (dur[right] - dur[left]) * nleft);

      value1 = min(value1,
                   dp[left][right - 1][0] + (dur[right] - dur[left]) * nleft);
      value1 = min(value1, dp[left][right - 1][1] +
                               (dur[right] - dur[right - 1]) * nleft);
    }
  }

  return min(dp[0][n - 1][0], dp[0][n - 1][1]);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}