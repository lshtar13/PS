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

cll N = 4e4;
ll n, nums[N] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  vll lis;
  lis.emplace_back(nums[0]);
  for (ll i = 1; i < n; ++i) {
    auto it = lower_bound(lis.begin(), lis.end(), nums[i]);
    if (it == lis.end()) {
      lis.emplace_back(nums[i]);
    } else {
      *it = nums[i];
    }
  }

  cout << lis.size() << "\n";

  return 0;
}