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
cll D = 1e6, N = 1e5;
ll nums[N] = {}, dp[2][D] = {{}};

ll solve() {
  ll d, n, result = 0;
  cin >> d >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  for (ll r = 0; r < d; ++r) {
    dp[0][r] = 0;
    if (r == (nums[0] % d)) {
      dp[0][r] = 1;
    }
  }
  result += dp[0][0];

  ll cur, prv;
  for (ll i = 1; i < n; ++i) {
    cur = i % 2, prv = !cur;

    for (ll r = 0; r < d; ++r) {
      dp[cur][r] = 0;
    }

    ++dp[prv][0];
    for (ll r = 0; r < d; ++r) {
      dp[cur][(r + nums[i]) % d] += dp[prv][r];
    }

    result += dp[cur][0];
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll c;
  cin >> c;
  while (c--) {
    cout << solve() << "\n";
  }

  return 0;
}