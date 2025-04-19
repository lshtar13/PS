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

cll N = 10, M = 10, STATUS = 1 << 10;
ll n, m, dp[N][STATUS] = {{}};
bool mat[N][M] = {{}};

ll calc(ll status) {
  ll result = 0;
  for (ll i = 0; i < m; ++i) {
    result += bool(status & (1 << i));
  }

  return result;
}

bool avail(ll line, ll nstatus, ll pstatus) {
  bool newStatus[M] = {}, prvStatus[M] = {};
  for (ll i = 0; i < m; ++i) {
    newStatus[i] = bool(nstatus & (1 << i));
    prvStatus[i] = bool(pstatus & (1 << i));
  }

  for (ll i = 0; i < m; ++i) {
    if (!newStatus[i]) {
      continue;
    }

    if (!mat[line][i]) {
      return false;
    }

    if (i > 0 && newStatus[i - 1]) {
      return false;
    }

    if (i < m - 1 && newStatus[i + 1]) {
      return false;
    }
  }

  for (ll i = 0; i < m; ++i) {
    if (!prvStatus[i]) {
      continue;
    }

    if (i > 0 && newStatus[i - 1]) {
      return false;
    }

    if (i < n - 1 && newStatus[i + 1]) {
      return false;
    }
  }

  return true;
}

ll find(ll line, ll pstatus) {
  if (line < 0) {
    return 0;
  } else if (dp[line][pstatus] != -1) {
    return dp[line][pstatus];
  }

  ll &result = dp[line][pstatus] = 0;
  for (ll nstatus = 0; nstatus < (1 << m); ++nstatus) {
    if (avail(line, nstatus, pstatus)) {
      result = max(result, find(line - 1, nstatus) + calc(nstatus));
    }
  }

  return result;
}

ll solve() {
  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < m; ++l) {
      char c;
      cin >> c;
      mat[i][l] = c == '.';
    }
  }

  return find(n - 1, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    memset(dp, -1, sizeof(dp));
    cout << solve() << "\n";
  }

  return 0;
}