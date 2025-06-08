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

// bfs?

cll N = 1000, M = 1000, K = 1000,
    directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m, k, mat[N][M] = {{}}, checked[N][M][4] = {{{}}};
bool blocked[N][M] = {{}};
pll src, dst;

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < m && !blocked[i][l];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < m; ++l) {
      char c;
      cin >> c;
      blocked[i][l] = c == '#';
    }
  }
  cin >> src.first >> src.second >> dst.first >> dst.second;
  --src.first, --src.second, --dst.first, --dst.second;

  memset(mat, -1, sizeof(mat));
  qpll q;
  q.push(src);
  mat[src.first][src.second] = 0;
  while (!q.empty()) {
    ll i, l;
    tie(i, l) = q.front();
    q.pop();
    for (ll d = 0; d < 4; ++d) {
      for (ll ni, nl, dk = 1; dk <= k; ++dk) {
        ni = i + directions[d][0] * dk, nl = l + directions[d][1] * dk;
        if (!isValidCord(ni, nl)) {
          break;
        }

        if (mat[ni][nl] == -1) {
          mat[ni][nl] = mat[i][l] + 1;
          q.push({ni, nl});
        } else if (mat[ni][nl] > mat[i][l]) {
          continue;
        } else {
          break;
        }
      }
    }
  }

  cout << mat[dst.first][dst.second] << "\n";

  return 0;
}