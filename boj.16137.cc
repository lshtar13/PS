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

typedef tuple<ll, ll, ll> info_t;

cll N = 10, M = 20, INF = N * N + 1,
    directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, mat[N][N] = {{}}, dists[N][N] = {{}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n && mat[i][l];
}

ll dijkstra() {
  priority_queue<info_t, vector<info_t>, greater<info_t>> pq;
  memset(dists, 0x3f3f3f3f, sizeof(dists));
  dists[0][0] = 0;
  pq.push({0, 0, 0});
  for (ll dist, i, l; !pq.empty();) {
    tie(dist, i, l) = pq.top();
    pq.pop();

    if (dists[i][l] < dist) {
      continue;
    }

    for (auto &d : directions) {
      ll ni = i + d[0], nl = l + d[1], ndist;
      if (!isValidCord(ni, nl)) {
        continue;
      } else if (mat[i][l] >= 2 && mat[ni][nl] >= 2) {
        continue;
      }

      ndist = mat[ni][nl] * (dist / mat[ni][nl] + 1);
      if (dists[ni][nl] > ndist) {
        dists[ni][nl] = ndist;
        pq.push({ndist, ni, nl});
      }
    }
  }

  return dists[n - 1][n - 1];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> mat[i][l];
    }
  }

  ll result = dijkstra();
  FOR2(i, l, n, n) {
    if (mat[i][l]) {
      continue;
    }

    if (i > 0 && i < n - 1 && mat[i - 1][l] == 1 && mat[i + 1][l] == 1) {
    } else if (l > 0 && l < n - 1 && mat[i][l - 1] == 1 && mat[i][l + 1] == 1) {
    } else if (i == 0 && l == n - 1 && mat[i][l - 2] == 1 &&
               mat[i + 1][l - 1] == 1) {
    } else if (i == n - 1 && l == 0 && mat[i - 2][0] == 1 &&
               mat[i][l + 1] == 1) {
    } else {
      continue;
    }

    mat[i][l] = m;
    result = min(result, dijkstra());
    mat[i][l] = 0;
  }

  cout << result << "\n";

  return 0;
}