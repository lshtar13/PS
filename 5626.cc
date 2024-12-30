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
ll n, nums[N] = {};
int dp[N / 2 + 1][N] = {};

ll find(ll prv, ll idx) {
  ll result;
  if (idx >= n) {
    return 1;
  } else if (dp[prv][idx] != -1) {
    goto END;
  }

  if (nums[idx] != -1) {
    if (abs(prv - nums[idx]) > 1) {
      result = 0;
    } else {
      result = find(nums[idx], idx + 1);
    }
  } else {
    result = 0;
    if (prv + 1 <= n / 2) {
      result += find(prv + 1, idx + 1);
    }
    result += find(prv, idx + 1);
    if (prv >= 1) {
      result += find(prv - 1, idx + 1);
    }
  }

  result %= INF;
  dp[prv][idx] = result;

END:
  return dp[prv][idx];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  if (nums[0] != -1 && nums[0] != 0) {
    cout << "0\n";
  } else if (nums[n - 1] != -1 && nums[n - 1] != 0) {
    cout << "0\n";
  } else {
    nums[0] = nums[n - 1] = 0;
    cout << find(0, 1) << "\n";
  }

  return 0;
}