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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 14, M = 14, Status = 1 << M, Mod = 9901;
ll n, m;
int dp[N][Status] = {{}};

int check(ll, ll);

int dfs(cll idx, ll i, cll status, ll nstatus) {
  if (i >= m) {
    return check(idx + 1, nstatus);
  } else if (status & (1 << i)) {
    return dfs(idx, i + 1, status, nstatus);
  }

  int result = 0;
  if (idx < n - 1) {
    result += dfs(idx, i + 1, status, nstatus | (1 << i)), result %= Mod;
  }

  if (i < m - 1 && !(status & (1 << (i + 1)))) {
    result += dfs(idx, i + 1, status | (1 << (i + 1)), nstatus), result %= Mod;
  }

  return result;
}

int check(ll idx, ll status) {
  if (idx == n) {
    return 1;
  } else if (dp[idx][status] != -1) {
    return dp[idx][status];
  }

  return dp[idx][status] = dfs(idx, 0, status, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  memset(dp, -1, sizeof(dp));

  cout << check(0, 0) << "\n";

  return 0;
}