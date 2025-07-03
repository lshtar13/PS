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

cll N = 14, M = 14, CLASS = 5;
cll values[CLASS][CLASS] = {{10, 8, 7, 5, 1},
                            {8, 6, 4, 3, 1},
                            {7, 4, 3, 2, 1},
                            {5, 3, 2, 2, 1},
                            {1, 1, 1, 1, 0}};
ll n, m, mat[N][M] = {{}}, dp[N][1 << M] = {{}};

ll check(ll, ll);

ll dfs(ll i, ll l, ll status, ll nstatus) {
  if (l >= m) {
    return check(i + 1, nstatus);
  } else if (status & (1 << l)) {
    return dfs(i, l + 1, status, nstatus);
  }

  ll result = dfs(i, l + 1, status, nstatus);
  if (l < m - 1 && !(status & (1 << (l + 1)))) {
    result = max(result, values[mat[i][l]][mat[i][l + 1]] +
                             dfs(i, l + 2, status, nstatus));
  }

  if (i < n - 1) {
    result = max(result, values[mat[i][l]][mat[i + 1][l]] +
                             dfs(i, l + 1, status, nstatus | (1 << l)));
  }

  return result;
}

ll check(ll idx, ll status) {
  if (idx == n) {
    return 0;
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
  FOR(i, n) {
    cin.ignore();
    FOR(l, m) {
      char c;
      cin >> c;
      mat[i][l] = min(4, c - 'A');
    }
  }

  memset(dp, -1, sizeof(dp));
  cout << check(0, 0) << "\n";

  return 0;
}