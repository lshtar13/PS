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

cll N = 13, M = 10, C = 20, STATUS = 1 << N;
ll n, m, c, weights[N] = {}, dp[M][C + 1][STATUS] = {{{}}};

ll findDP(ll bag, ll level, ll status) {
  if (bag == m) {
    return 0;
  } else if (dp[bag][level][status] != -1) {
    return dp[bag][level][status];
  }

  ll &result = dp[bag][level][status] = findDP(bag + 1, 0, status);
  for (ll i = 0, nstatus; i < n; ++i) {
    if (status & (1 << i)) {
      continue;
    } else if (weights[i] + level > c) {
      continue;
    }
    nstatus = status | (1 << i);
    result = max(result, findDP(bag, weights[i] + level, nstatus) + 1);
    result = max(result, findDP(bag + 1, 0, nstatus) + 1);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> c;
  for (ll i = 0; i < n; ++i) {
    cin >> weights[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << findDP(0, 0, 0) << "\n";

  return 0;
}