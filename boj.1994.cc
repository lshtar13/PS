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

cll N = 2000, NUM = 1e9;
ll n, nums[N] = {}, dp[N][N] = {{}};

ll find(ll fst, ll snd) {
  if (dp[fst][snd] != -1) {
    return dp[fst][snd];
  }

  dp[fst][snd] = 2;
  ll nxt = nums[snd] + nums[snd] - nums[fst];
  ll pos = lower_bound(nums + snd + 1, nums + n, nxt) - nums;
  if (pos < n && nums[pos] == nxt) {
    dp[fst][snd] = find(snd, pos) + 1;
  }

  return dp[fst][snd];
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
  sort(nums, nums + n);

  ll result = 1;
  for (ll fst = 0; fst < n; ++fst) {
    for (ll snd = fst + 1; snd < n; ++snd) {
      result = max(result, find(fst, snd));
    }
  }

  cout << result << "\n";

  return 0;
}