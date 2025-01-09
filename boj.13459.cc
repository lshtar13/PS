#include <bits/stdc++.h>
#include <queue>
#include <tuple>

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

cll N = 10, M = 10, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m, mat[N][M] = {{}}, goal[2];

typedef tuple<ll, ll, ll, ll, ll> status_t;
typedef tuple<ll, ll> cord_t;

inline bool isGoal(ll c0, ll c1) { return c0 == goal[0] && c1 == goal[1]; }

inline bool isValid(ll c0, ll c1) {
  return c0 >= 0 && c0 < n && c1 >= 0 && c1 < m && !mat[c0][c1];
}

cord_t move(ll c0, ll c1, ll d0, ll d1) {
  while (isValid(c0 + d0, c1 + d1)) {
    c0 += d0, c1 += d1;
    if (c0 == goal[0] && c1 == goal[1]) {
      break;
    }
  }
  return make_tuple(c0, c1);
}

status_t check(ll d, status_t &prev) {
  ll r0, r1, b0, b1, w, R0, R1, B0, B1, W;
  tie(r0, r1, b0, b1, w) = prev;
  switch (d) {
  case 0:
    if (r1 == b1 && r0 > b0) {
      tie(R0, R1) = move(r0, r1, directions[0][0], directions[0][1]);
      mat[R0][R1] = !isGoal(R0, R1) ? -2 : 0;
      tie(B0, B1) = move(b0, b1, directions[0][0], directions[0][1]);
      mat[R0][R1] = 0;
    } else {
      tie(B0, B1) = move(b0, b1, directions[0][0], directions[0][1]);
      mat[B0][B1] = !isGoal(B0, B1) ? -2 : 0;
      tie(R0, R1) = move(r0, r1, directions[0][0], directions[0][1]);
      mat[B0][B1] = 0;
    }
    break;
  case 1:
    if (r1 == b1 && r0 < b0) {
      tie(R0, R1) = move(r0, r1, directions[1][0], directions[1][1]);
      mat[R0][R1] = !isGoal(R0, R1) ? -2 : 0;
      tie(B0, B1) = move(b0, b1, directions[1][0], directions[1][1]);
      mat[R0][R1] = 0;
    } else {
      tie(B0, B1) = move(b0, b1, directions[1][0], directions[1][1]);
      mat[B0][B1] = !isGoal(B0, B1) ? -2 : 0;
      tie(R0, R1) = move(r0, r1, directions[1][0], directions[1][1]);
      mat[B0][B1] = 0;
    }
    break;
  case 2:
    if (r0 == b0 && r1 > b1) {
      tie(R0, R1) = move(r0, r1, directions[2][0], directions[2][1]);
      mat[R0][R1] = !isGoal(R0, R1) ? -2 : 0;
      tie(B0, B1) = move(b0, b1, directions[2][0], directions[2][1]);
      mat[R0][R1] = 0;
    } else {
      tie(B0, B1) = move(b0, b1, directions[2][0], directions[2][1]);
      mat[B0][B1] = !isGoal(B0, B1) ? -2 : 0;
      tie(R0, R1) = move(r0, r1, directions[2][0], directions[2][1]);
      mat[B0][B1] = 0;
    }
    break;
  case 3:
    if (r0 == b0 && r1 < b1) {
      tie(R0, R1) = move(r0, r1, directions[3][0], directions[3][1]);
      mat[R0][R1] = !isGoal(R0, R1) ? -2 : 0;
      tie(B0, B1) = move(b0, b1, directions[3][0], directions[3][1]);
      mat[R0][R1] = 0;
    } else {
      tie(B0, B1) = move(b0, b1, directions[3][0], directions[3][1]);
      mat[B0][B1] = !isGoal(B0, B1) ? -2 : 0;
      tie(R0, R1) = move(r0, r1, directions[3][0], directions[3][1]);
      mat[B0][B1] = 0;
    }
    break;
  }

  if (isGoal(B0, B1)) {
    W = -1;
  } else if (isGoal(R0, R1)) {
    W = -2;
  } else if (r0 == R0 && r1 == R1 && b0 == B0 && b1 == B1) {
    W = -1;
  } else {
    W = w + 1;
  }
//   cout << r0 << "/" << r1 << " " << b0 << "/" << b1 << " ";
//   cout << R0 << "/" << R1 << " " << B0 << "/" << B1 << " ";
//   cout << W << "\n";
  return make_tuple(R0, R1, B0, B1, W);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  status_t init;
  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < m; ++l) {
      char c;
      cin >> c;
      switch (c) {
      case '#':
        mat[i][l] = -1;
        break;
      case '.':
        mat[i][l] = 0;
        break;
      case 'O':
        goal[0] = i, goal[1] = l;
        break;
      case 'R':
        get<0>(init) = i, get<1>(init) = l;
        break;
      case 'B':
        get<2>(init) = i, get<3>(init) = l;
        break;
      }
    }
  }
  get<4>(init) = 0;

  queue<status_t> q;
  q.push(init);
  while (!q.empty()) {
    status_t status = q.front();
    q.pop();

    if (get<4>(status) >= 10) {
      continue;
    }

    for (auto d : {0, 1, 2, 3}) {
      status_t result = check(d, status);
      switch (get<4>(result)) {
      case -1:
        break;
      case -2:
        cout << 1 << "\n";
        goto END;
        break;
      default:
        q.push(result);
      }
    }
  }
  cout << 0 << "\n";
END:

  return 0;
}