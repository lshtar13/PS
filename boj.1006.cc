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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 1e4, W = 1e4, Inf = N * 2;
ll n, w, enemies[N][2] = {}, dp[N][4][4] = {{{}}};

ll check(ll idx, ll status, ll tail) {
  if (idx >= n) {
    return 0;
  }

  ll &value = dp[idx][status][tail];
  if (value != -1) {
    return value;
  }

  value = Inf;
  switch (status) {
  case 0:
    value = min(value, check(idx + 1, 0, tail) + 2);
    if (enemies[idx][0] + enemies[idx][1] <= w) {
      value = min(value, check(idx + 1, 0, tail) + 1);
    }

    if (enemies[idx][0] + enemies[idx + 1][0] <= w) {
      if (idx + 1 != n - 1 || !(tail & (1 << 0))) {
        value = min(value, check(idx + 1, 1, tail) + 2);
      }
    }

    if (enemies[idx][1] + enemies[idx + 1][1] <= w) {
      if (idx + 1 != n - 1 || !(tail & (1 << 1))) {
        value = min(value, check(idx + 1, 2, tail) + 2);
      }
    }

    if (enemies[idx][0] + enemies[idx + 1][0] <= w &&
        enemies[idx][1] + enemies[idx + 1][1] <= w) {
      if (idx + 1 != n - 1 || tail == 0) {
        value = min(value, check(idx + 2, 0, tail) + 2);
      }
    }
    break;

  case 1:
    value = min(value, check(idx + 1, 0, tail) + 1);
    if (enemies[idx][1] + enemies[idx + 1][1] <= w) {
      if (idx + 1 != n - 1 || !(tail & (1 << 1))) {
        value = min(value, check(idx + 1, 2, tail) + 1);
      }
    }
    break;

  case 2:
    value = min(value, check(idx + 1, 0, tail) + 1);
    if (enemies[idx][0] + enemies[idx + 1][0] <= w) {
      if (idx + 1 != n - 1 || !(tail & (1 << 0))) {
        value = min(value, check(idx + 1, 1, tail) + 1);
      }
    }
    break;

  case 3:
    value = check(idx + 2, 0, tail);
    break;
  }

  return value;
}

ll solve() {
  ll result = Inf;
  cin >> n >> w;
  FOR(i, 0, 2) FOR(l, 0, n) { cin >> enemies[l][i]; }
  memset(dp, -1, sizeof(dp));
  FOR(status, 0, 4) FOR(tail, 0, 4) {
    ll &value = dp[n - 1][status][tail];
    switch (status ^ tail) {
    case 0:
      if (enemies[n - 1][0] + enemies[n - 1][1] <= w) {
        value = 1;
      } else {
        value = 2;
      }
      break;
    case 1:
    case 2:
      value = 1;
      break;
    case 3:
      value = 0;
      break;
    }
  }

  result = min(result, check(0, 0, 0));
  if (n >= 2 && enemies[0][1] + enemies[n - 1][1] <= w) {
    result = min(result, check(1, 0, 2) + 2);
    if (enemies[0][0] + enemies[n - 1][0] <= w) {
      result = min(result, check(1, 0, 3) + 2);
    }
  }
  if (n >= 2 && enemies[0][0] + enemies[n - 1][0] <= w) {
    result = min(result, check(1, 0, 1) + 2);
  }

  if (n >= 2 && enemies[0][0] + enemies[1][0] <= w &&
      enemies[0][1] + enemies[n - 1][1] <= w) {
    result = min(result, check(1, 1, 2) + 2);
  }

  if (n >= 2 && enemies[0][1] + enemies[1][1] <= w &&
      enemies[0][0] + enemies[n - 1][0] <= w) {
    result = min(result, check(1, 2, 1) + 2);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}