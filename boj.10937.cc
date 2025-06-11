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

cll Class = 4, N = 11,
    prices[Class][Class] = {
        {100, 70, 40, 0}, {70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0}};
ll n, mat[N][N] = {{}}, dp[N + 1][1 << N] = {{}};
bool checked[N][N] = {{}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n;
}

ll check(ll, ll);

ll dfs(ll i, ll l, ll status, ll nstatus) {
  if (l >= n) {
    return check(i + 1, nstatus);
  } else if (status & (1 << l)) {
    return dfs(i, l + 1, status, nstatus);
  }

  ll result = 0;
  // skip
  result = max(result, dfs(i, l + 1, status, nstatus));

  // right
  if (l < n - 1 && !(status & (1 << (l + 1)))) {
    result = max(result, dfs(i, l + 2, status | (1 << (l + 1)), nstatus) +
                             prices[mat[i][l]][mat[i][l + 1]]);
  }
  // under
  if (i < n - 1 && !(nstatus & (1 << l))) {
    result = max(result, dfs(i, l + 1, status, nstatus | (1 << l)) +
                             prices[mat[i][l]][mat[i + 1][l]]);
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

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < n; ++l) {
      char c;
      cin >> c;
      if (c < 'F') {
        mat[i][l] = c - 'A';
      } else {
        mat[i][l] = 3;
      }
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << check(0, 0) << "\n";

  return 0;
}