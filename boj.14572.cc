#include <algorithm>
#include <bits/stdc++.h>
#include <utility>

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

cll N = 1e5, L = 1e6;
ll n, l, dp[2][N];
vll dp[2]; // up / low
vpll cords;

ll find(ll div, ll idx) {
  if (dp[div][idx] != -1) {
    return dp[div][idx];
  }

  ll up = cords[idx].first, low = cords[idx].second, dist = abs(up - low) + l,
     result = dist;
  if (!div) {
    for (ll _idx = idx + 1; _idx < n; ++_idx) {
      if (cords[_idx].second != low) {
        continue;
      }
      result = max(result, find(!div, _idx) + dist);
    }
  } else {
    for (ll _idx = idx + 1; _idx < n && cords[_idx].first == up; ++_idx) {
      result = max(result, find(!div, _idx) + dist);
    }
  }

  return dp[div][idx] = result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> l;
  dp[0].resize(n, -1);
  dp[1].resize(n, -1);
  cords.resize(n);
  for (auto &cord : cords) {
    cin >> cord.first >> cord.second;
  }
  sort(cords.begin(), cords.end());

  ll result = 0;
  for (ll div = 0; div < 2; ++div) {
    for (ll idx = 0; idx < n; ++idx) {
      result = max(result, find(div, idx));
    }
  }

  cout << result << "\n";

  return 0;
}