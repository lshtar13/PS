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

cll N = 1e4, INF = 1e9 + 7;
ll n, nums[N] = {}, dp[2][N] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  if (nums[0] != -1 && nums[0] != 0) {
    cout << "0\n";
  } else if (nums[n - 1] != -1 && nums[n - 1] != 0) {
    cout << "0\n";
  } else {
    nums[0] = nums[n - 1] = 0, dp[n % 2][0] = 1;
    for (ll idx = n - 1; idx >= 0; --idx) {
      for (ll num = 0; num <= n / 2; ++num) {
        if (nums[idx] != -1 && nums[idx] != num) {
          dp[idx % 2][num] = 0;
          continue;
        }

        dp[idx % 2][num] = dp[(idx + 1) % 2][num];
        if (num >= 1) {
          dp[idx % 2][num] += dp[(idx + 1) % 2][num - 1];
        }
        if (num < n / 2) {
          dp[idx % 2][num] += dp[(idx + 1) % 2][num + 1];
        }
        dp[idx % 2][num] %= INF;
      }
    }

    cout << dp[0][0] << "\n";
  }

  return 0;
}