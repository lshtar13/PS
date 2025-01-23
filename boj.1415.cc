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
cll N = 50, P = 1e4;
ll n, sum = 0, cur, prv;
ll dp[2][N * P + 1] = {{}};
vpll nums;
map<ll, ll> inputs;
bool isNotPrime[N * P + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll num, i = 0; i < n; ++i) {
    cin >> num;
    inputs[num] = inputs[num] + 1;
  }

  for (auto &p : inputs) {
    sum += p.first * p.second;
    nums.emplace_back(make_pair(p.first, p.second));
  }

  n = nums.size(), dp[0][0] = 1, cur = 0, prv = 1;
  for (ll i = 1; i <= n; ++i) {
    ll price = nums[i - 1].first, num = nums[i - 1].second;
    cur = !cur, prv = !prv;
    for (ll p = 0; p <= sum; ++p) {
      dp[cur][p] = dp[prv][p];
      for (ll k = 1; k <= num; ++k) {
        if (p < price * k) {
          continue;
        }

        dp[cur][p] += dp[prv][p - price * k];
      }
    }
  }

  ll result = 0;
  for (ll num = 2; num <= sum; ++num) {
    if (isNotPrime[num]) {
      continue;
    }

    result += dp[cur][num];
    for (ll _num = num * 2; _num <= sum; _num += num) {
      isNotPrime[_num] = true;
    }
  }

  cout << result << "\n";

  return 0;
}