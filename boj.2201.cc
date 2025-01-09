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

cll N_BIT = 101, K = 1e18;
ll k, dp[N_BIT][3] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0][0] = 0, dp[0][1] = 1, dp[0][2] = 1;
  for (ll b = 1; b < N_BIT; ++b) {
    dp[b][0] = dp[b - 1][0] + dp[b - 1][1];
    dp[b][1] = dp[b - 1][0];
    dp[b][2] = dp[b][0] + dp[b][1];
  }

  cin >> k;

  ll bit, sum, order;
  stack<ll> s;
  while (true) {
    for (bit = 0, sum = 0; sum < k; ++bit) {
      sum += dp[bit][2];
    }

    if (bit > 0) {
      k = dp[bit - 1][2] - (sum - k) - 1;
      s.push(bit);
    } else {
      break;
    }
  }

  ll prv = 0, cur;
  string result = "";
  while (!s.empty()) {
    cur = s.top();
    s.pop();

    for (ll i = 0; i < cur - prv - 1; ++i) {
      result = "0" + result;
    }

    result = "1" + result;
    prv = cur;
  }

  cout << result;

  return 0;
}