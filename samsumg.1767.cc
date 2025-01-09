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

cll N = 12, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, ncore, cores[N][2] = {{}}, mat[N][N] = {{}};

inline bool isValid(ll i, ll l) { return i >= 0 && i < n && l >= 0 && l < n; }

ll fillWay(ll i, ll l, ll d, ll idx) {
  ll wires = 0, di = directions[d][0], dl = directions[d][1];
  for (ll _i = i + di, _l = l + dl; isValid(_i, _l); _i += di, _l += dl) {
    if (mat[_i][_l]) {
      return -1;
    }
  }

  for (ll _i = i + di, _l = l + dl; isValid(_i, _l); _i += di, _l += dl) {
    mat[_i][_l] = idx, ++wires;
  }

  return wires;
}

void clearWay(ll i, ll l, ll d, ll idx) {
  ll di = directions[d][0], dl = directions[d][1];
  for (ll _i = i + di, _l = l + dl; isValid(_i, _l); _i += di, _l += dl) {
    if (mat[_i][_l] != idx) {
      return;
    }
  }

  for (ll _i = i + di, _l = l + dl; isValid(_i, _l); _i += di, _l += dl) {
    mat[_i][_l] = 0;
  }
}

pll find(ll idx, ll curCore, ll curWire) {
  if (idx == ncore) {
    return {0, 0};
    // no core, no wire
  }

  ll i = cores[idx][0], l = cores[idx][1], wires;
  pll result = find(idx + 1, curCore, curWire), _result;
  for (ll d = 0; d < 4; ++d) {
    if ((wires = fillWay(i, l, d, idx + 5)) == -1) {
      continue;
    }
    _result = find(idx + 1, curCore + 1, curWire);
    result = min(result, {_result.first - 1, _result.second + wires});

    clearWay(i, l, d, idx + 5);
  }

  return result;
}

ll solve() {
  ncore = 0;
  cin >> n;
  FOR2(i, l, n, n) {
    cin >> mat[i][l];
    if (mat[i][l]) {
      cores[ncore][0] = i, cores[ncore][1] = l;
      ++ncore;
    }
  }
  auto result = find(0, 0, 0);
  return result.second;
}

int main(void) {
  //   ios::sync_with_stdio(false);
  //   cin.tie(NULL);
  //   cout.tie(NULL);

  ll t;
  cin >> t;
  for (ll i = 1; i <= t; ++i) {
    cout << "#" << i << " " << solve() << "\n";
  }

  return 0;
}