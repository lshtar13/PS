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

cll R = 500, C = 500, INF = 3e5,
    directions[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
ll r, c, board[R][C] = {{}}, toward[R][C] = {{}}, results[R][C] = {{}};

inline bool isValid(ll i, ll l) { return i >= 0 && i < r && l >= 0 && l < c; }

pll find(ll i, ll l) {
  if (toward[i][l] != -1) {
    return {toward[i][l] / c, toward[i][l] % c};
  }

  pll result = {i, l};
  ll next = board[i][l];
  for (auto &d : directions) {
    ll _i = i + d[0], _l = l + d[1];
    if (!isValid(_i, _l)) {
      continue;
    }

    if (next > board[_i][_l]) {
      result = find(_i, _l);
      next = board[_i][_l];
    }
  }

  toward[i][l] = result.first * c + result.second;
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  FOR2(i, l, r, c) { cin >> board[i][l]; }
  memset(toward, -1, sizeof(toward));

  FOR2(i, l, R, C) {
    pll dest = find(i, l);
    ++results[dest.first][dest.second];
  }

  for (ll i = 0; i < r; ++i) {
    for (ll l = 0; l < c; ++l) {
      cout << results[i][l] << " ";
    }
    cout << "\n";
  }

  return 0;
}