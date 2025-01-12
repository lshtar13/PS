#include <bits/stdc++.h>
#include <climits>

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

cll N = 2500;
ll n, stones[N + 1] = {}, dp[N + 1][N + 1] = {{}};

ll find(ll idx, ll nstone) {
  if (idx == n) {
    return 0;
  } else if (nstone == 0) {
    return find(idx + 1, stones[idx + 1]);
  }

  if (dp[idx][nstone] != -1) {
    return dp[idx][nstone];
  }

  ll result = LLONG_MAX;
  // self
  result = min(result, find(idx + 1, stones[idx + 1]) + 1);
  // together
  if (nstone <= stones[idx + 1]) {
    result = min(result, find(idx + 1, stones[idx + 1] - nstone) + 1);
  }
  // self + together
  if (nstone > stones[idx + 1] && stones[idx + 1]) {
    result = min(result, find(idx + 1, 0) + 2);
  }

  return dp[idx][nstone] = result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll s = 0; s < n; ++s) {
    cin >> stones[s];
  }

  memset(dp, -1, sizeof(dp));
  cout << find(0, stones[0]) << "\n";

  return 0;
}
