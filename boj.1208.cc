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

cll N = 40, S = 1000000, MAX_KIND = 1 << (N / 2);
ll n, s, nums[N] = {};
vll s0 = {0}, s1 = {0};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  for (ll i = 0; i < n / 2; ++i) {
    for (ll l = 0, limit = s0.size(); l < limit; ++l) {
      s0.emplace_back(s0[l] + nums[i]);
    }
  }

  for (ll i = n / 2; i < n; ++i) {
    for (ll l = 0, limit = s1.size(); l < limit; ++l) {
      s1.emplace_back(s1[l] + nums[i]);
    }
  }

  sort(s0.begin(), s0.end());
  sort(s1.begin(), s1.end());

  ll result = 0, idx0 = 0, idx1 = s1.size() - 1;
  while (idx0 < s0.size() && idx1 >= 0) {
    ll sum = s0[idx0] + s1[idx1], _idx0 = idx0, _idx1 = idx1;
    if (sum == s) {
      while (_idx0 < s0.size() && s0[idx0] == s0[_idx0]) {
        ++_idx0;
      }
      while (_idx1 >= 0 && s1[idx1] == s1[_idx1]) {
        --_idx1;
      }

      result += (_idx0 - idx0) * (idx1 - _idx1);
      idx0 = _idx0, idx1 = _idx1;
    } else if (sum > s) {
      --idx1;
    } else {
      ++idx0;
    }
  }

  // ll tgt = s, result = 0;
  // for (ll i = 0; i < s0.size(); ++i) {
  //   tgt = s - s0[i];
  //   auto lo = lower_bound(s1.begin(), s1.end(), tgt),
  //        up = upper_bound(s1.begin(), s1.end(), tgt);
  //   result += (up - lo);
  // }
  if (s == 0) {
    --result;
  }

  cout << result << "\n";

  return 0;
}

// 0 0 0 0 0 0