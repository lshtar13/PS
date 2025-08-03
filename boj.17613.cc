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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll T = 2000, X = 1e9, Y = 1e9, Power = 31, MaxMem = 1e3, MaxIdx = 16;
ll t, powers[Power] = {}, dp[MaxMem][MaxMem] = {{}};

ll check(ll left, ll right) {
  if (left > right) {
    return 0;
  } else if (right == 0) {
    return 0;
  }

  if (max(left, right) < MaxMem && dp[left][right] != -1) {
    return dp[left][right];
  }

  ll lbound, rbound, &result = dp[left][right];

  FOR(p, 0, Power) {
    if (left <= ((1 << (p + 1)) - 1)) {
      lbound = p;
      break;
    }
  }

  IFOR(p, Power - 1, 0) {
    if (right >= (1 << (p + 1)) - 1) {
      rbound = p;
      break;
    }
  }

  cout << left << "/" << lbound << " " << right << "/" << rbound << "\n";

  if (lbound < rbound) {
    return result =
               max({check(left, powers[lbound + 1] - 1),
                    check(powers[rbound], right), (rbound * (rbound + 1) / 2)});
  } else {
    ll offset = pow(2, lbound + 1) - 1;
    return result = check(left - offset, right - offset) + lbound + 1;
  }
}

int main(void) {
  // ios::sync_with_stdio(false);
  // cin.tie(NULL);
  // cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  dp[0][1] = 1;

  cin >> t;
  FOR(q, 0, t) {
    ll x, y;
    cin >> x >> y;
    cout << check(x, y) << "\n";
  }

  return 0;
}