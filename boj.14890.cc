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

cll N = 100, L = N;
ll n, len, mat[N + 2][N + 2] = {{}}, dp[N + 2][N + 2][2] = {{}};
// direction : 0 (horizontal) 1 (vertical)

inline bool valid(ll i, ll l) {
  return i >= 0 && i <= n + 1 && l >= 0 && l <= n + 1;
}
inline bool end(ll i, ll l, ll direction) {
  return direction ? i == n + 1 : l == n + 1;
}
inline bool begin(ll i, ll l, ll direction) {
  return direction ? i == 0 : l == 0;
}

bool check(ll i, ll l, ll direction) {
  bool result = false;
  ll di = direction, dl = !direction, _i = i + di, _l = l + dl, step, h, swp;

  // normal
  _i = i + di, _l = l + dl;
  if (begin(i, l, direction)) {
    result = check(_i, _l, direction);
  } else if (end(i, l, direction)) {
    result = true;
    goto END;
  } else if (mat[i][l] == mat[_i][_l] || end(_i, _l, direction)) {
    result = check(_i, _l, direction);
  }

UP:
  _i = i + di, _l = l + dl, h = mat[_i][_l];
  if (!begin(i, l, direction) && mat[i][l] != h) {
    goto DOWN;
  }

  for (step = 0; valid(_i, _l) && step < len; ++step) {
    if (h == mat[_i][_l]) {
      _i += di, _l += dl;
    } else {
      goto DOWN;
    }
  }

  if (step == len && valid(_i, _l)) {
    if (end(_i, _l, direction) || mat[_i][_l] - h == 1) {
      swp = mat[_i - di][_l - dl], mat[_i - di][_l - dl] = mat[_i][_l];
      result |= check(_i - di, _l - dl, direction);
      mat[_i - di][_l - dl] = swp;
    }
  }

DOWN:
  _i = i + di, _l = l + dl, h = mat[_i][_l];
  if (!begin(i, l, direction) && mat[i][l] != h + 1) {
    goto END;
  }

  for (step = 0; valid(_i, _l) && step < len; ++step) {
    if (mat[i][l] - 1 == mat[_i][_l]) {
      _i += di, _l += dl;
    } else {
      goto END;
    }
  }

  if (step == len && valid(_i, _l)) {
    if (end(_i, _l, direction) || h - mat[_i][_l] == 1) {
      swp = mat[_i - di][_l - dl], mat[_i - di][_l - dl] = mat[_i][_l];
      result |= check(_i - di, _l - dl, direction);
      mat[_i - di][_l - dl] = swp;
    }
  }

END:
  cout << i << " " << l << " " << direction << " " << result << "\n";
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> len;
  FOR2(i, l, n, n) { cin >> mat[i + 1][l + 1]; }

  cout << check(0, 5, 1) << "\n";

  // ll result = 0;
  // for (ll i = 1; i <= n; ++i) {
  //   result += check(i, 0, 0);
  //   result += check(0, i, 1);
  // }

  // cout << result << "\n";

  return 0;
}