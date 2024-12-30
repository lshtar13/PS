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

cll N = 20, M = N * N, FUEL = 5e5,
    directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
ll n, m, fuel, deliverd, mat[N][N] = {{}};
pll driver, srcs[M + 1], dsts[M + 1];

inline bool isValid(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n && mat[i][l] >= 0;
}

ll near(pll src) {
  ll visited[N][N] = {{}};
  qpll q;
  q.push(src);
  visited[src.first][src.second] = 1;
  while (!q.empty()) {
    ll i = q.front().first, l = q.front().second;
    q.pop();
    if (mat[i][l] > 0) {
      return mat[i][l];
    }

    for (auto &d : directions) {
      ll _i = i + d[0], _l = l + d[1];
      if (!isValid(_i, _l) || mat[_i][_l] < 0 || visited[_i][_l]) {
        continue;
      }

      visited[_i][_l] = visited[i][l] + 1;
      q.push({_i, _l});
    }
  }

  return -1;
}

ll move(pll src, pll dst) {
  ll visited[N][N] = {{}};
  qpll q;
  q.push(src);
  visited[src.first][src.second] = 1;
  while (!q.empty()) {
    ll i = q.front().first, l = q.front().second;
    if (q.front() == dst) {
      return visited[i][l] - 1;
    }
    q.pop();

    for (auto &d : directions) {
      ll _i = i + d[0], _l = l + d[1];
      if (!isValid(_i, _l) || mat[_i][_l] < 0 || visited[_i][_l]) {
        continue;
      }

      visited[_i][_l] = visited[i][l] + 1;
      q.push({_i, _l});
    }
  }

  return -1;
}

ll search() {
  ll idx = near(driver), dist;
  if (idx < 0) {
    return -1;
  }

  mat[srcs[idx].first][srcs[idx].second] = 0;
  dist = move(driver, srcs[idx]);
  if (dist < 0) {
    return -1;
  }

  if ((fuel -= dist) < 0) {
    return -1;
  }

  dist = move(srcs[idx], dsts[idx]);
  if (dist < 0) {
    return -1;
  }

  if ((fuel -= dist) < 0) {
    return -1;
  }

  driver = dsts[idx];
  return fuel += 2 * dist;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> fuel;
  FOR2(i, l, n, n) {
    cin >> mat[i][l];
    mat[i][l] = -mat[i][l];
  }

  cin >> driver.first >> driver.second;
  --driver.first, --driver.second;

  for (ll i = 1; i <= m; ++i) {
    cin >> srcs[i].first >> srcs[i].second >> dsts[i].first >> dsts[i].second;
    --srcs[i].first, --srcs[i].second, --dsts[i].first, --dsts[i].second;
    mat[srcs[i].first][srcs[i].second] = i;
  }

  deliverd = 0;
  while (fuel >= 0 && deliverd < m && search() != -1) {
    ++deliverd;
  }

  if (deliverd < m) {
    cout << deliverd << "\n";
    cout << -1 << "\n";
  } else {
    cout << fuel << "\n";
  }

  return 0;
}