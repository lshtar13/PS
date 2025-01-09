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
const ll INF = 100, coins[3] = {25, 10, 1};
vll dp(100, INF);

// 1, 10, 25;
ll find(ll price) {
  if (dp[price] != INF) {
    return dp[price];
  } else if (price == 0) {
    return dp[price] = 0;
  }

  for (auto coin : coins) {
    if (price >= coin) {
      dp[price] = min(dp[price], find(price - coin) + 1);
    }
  }

  return dp[price];
}

ll solve(ll price) {
  ll result = 0;
  while (price) {
    result += find(price % 100);
    price /= 100;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    ll price;
    cin >> price;
    cout << solve(price) << "\n";
  }

  return 0;
}