#include <algorithm>
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

cll W = 799994, N = 5000, A = 2e5;
ll w, n, nums[N + 1] = {}, sums[N * N] = {}, idxs = 1;

// mitm ==> 2개, 3개, 4개 중첩되는 것 제외

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> w >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }
  sort(nums, nums + n);

  for (ll i = 0; i < n; ++i) {
    for (ll l = i + 1; l < n; ++l) {
      sums[idxs++] = nums[i] + nums[l];
    }
  }
  sort(sums, sums + idxs);

  ll left = 0, right = idxs - 1, sum, result = 0;
  while (left <= right) {
    sum = sums[left] + sums[right];
    if (sum < w) {
      ++left;
    } else if (sum > w) {
      --right;
    } else {
      ll nleft = left + 1, nright = right - 1;
      while (sums[nleft] == sums[left]) {
        ++nleft;
      }
      while (sums[nright] == sums[right]) {
        --nright;
      }

      result += (nleft - left) * (right - nright);
      left = nleft, right = nright;
    }
  }

  // 2-2
  for (ll i = 0; i < n; ++i) {
    for (ll l = i + 1; l < n; ++l) {
      if (2 * (nums[i] + nums[l]) == w) {
        --result;
      }
    }
  }

  // 2-1-1
  for (ll i = 0; i < n; ++i) {
    for (ll l = i + 1; l < n; ++l) {
      ll sum = nums[i] + nums[l];
      if ((w - sum) % 2) {
        continue;
      }

      ll idx = lower_bound(nums, nums + n, (w - sum) / 2) - nums;
      if (idx != i && idx != l) {
        --result;
      }
    }
  }

  if (result > 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }

  return 0;
}