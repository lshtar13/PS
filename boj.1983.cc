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

cll MAX_N = 400;
ll n, size0, size1, dp[MAX_N][MAX_N] = {{}};
vll nums[2];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll x, i = 0; i < n; ++i) {
    cin >> x;
    if (x) {
      nums[0].emplace_back(x);
    }
  }
  for (ll x, i = 0; i < n; ++i) {
    cin >> x;
    if (x) {
      nums[1].emplace_back(x);
    }
  }
  size0 = nums[0].size(), size1 = nums[1].size();

    for(ll i = 0; i<size0; ++i)
    {
        dp[i][0] = 
    }

  return 0;
}