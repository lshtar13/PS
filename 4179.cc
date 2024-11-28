#include <bits/stdc++.h>
#include <climits>

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

cll R = 1000, C = 1000, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll r, c, firebase, startPoint, mat[R][C] = {{}}, fireTime[R][C] = {{}},
                               escapeTime[R][C] = {{}};

inline bool isValid(ll i, ll l) {
  return i >= 0 && i < r && l >= 0 && l < c && !mat[i][l];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  qll q0, q1;
  cin >> r >> c;
  FOR1(i, r) {
    cin.ignore();
    FOR1(l, c) {
      char m;
      cin >> m;

      mat[i][l] = (m == '#');
      switch (m) {
      case 'J':
        q1.push(i * c + l);
        escapeTime[i][l] = 1;
        break;
      case 'F':
        q0.push(i * c + l);
        fireTime[i][l] = 1;
        break;
      }
    }
  }

  while (!q0.empty()) {
    ll i = q0.front() / c, l = q0.front() % c;
    q0.pop();

    for (auto &d : directions) {
      ll _i = i + d[0], _l = l + d[1];
      if (!isValid(_i, _l) || fireTime[_i][_l]) {
        continue;
      }

      fireTime[_i][_l] = fireTime[i][l] + 1;
      q0.push(_i * c + _l);
    }
  }

  while (!q1.empty()) {
    ll i = q1.front() / c, l = q1.front() % c, newTime = escapeTime[i][l] + 1;
    q1.pop();

    for (auto &d : directions) {
      ll _i = i + d[0], _l = l + d[1];
      if (!isValid(_i, _l) || escapeTime[_i][_l] ||
          (fireTime[_i][_l] && newTime >= fireTime[_i][_l])) {
        continue;
      }

      escapeTime[_i][_l] = newTime;
      q1.push(_i * c + _l);
    }
  }

  ll result = LLONG_MAX;
  for (ll i = 0; i < r; ++i) {
    if (escapeTime[i][0]) {
      result = min(result, escapeTime[i][0]);
    }

    if (escapeTime[i][c - 1]) {
      result = min(result, escapeTime[i][c - 1]);
    }
  }

  for (ll i = 0; i < c; ++i) {
    if (escapeTime[0][i]) {
      result = min(result, escapeTime[0][i]);
    }

    if (escapeTime[r - 1][i]) {
      result = min(result, escapeTime[r - 1][i]);
    }
  }

  if (result == LLONG_MAX) {
    cout << "IMPOSSIBLE" << '\n';
  } else {
    cout << result << "\n";
  }

  return 0;
}