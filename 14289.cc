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

cll N = 50, M = 1000, INF = 1e9 + 7;
ll n, m, d, square[30][N][N] = {{{}}};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  cin >> n >> m;
  for (ll a, b, i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    square[0][a][b] = square[0][b][a] = 1;
  }

  cin >> d;
  for (ll s = 1; (1 << s) <= d; ++s) {
    for (ll a = 0; a < n; ++a) {
      for (ll b = 0; b < n; ++b) {
        for (ll mid = 0; mid < n; ++mid) {
          square[s][a][b] +=
              (square[s - 1][a][mid] * square[s - 1][mid][b]) % INF;
          square[s][a][b] %= INF;
        }
      }
    }
  }

  ll result[N][N][N] = {{{}}}, cnt = 0;
  for (ll i = 0; i < n; ++i) {
    result[cnt][i][i] = 1;
  }

  for (ll i = 0; (1 << i) <= d; ++i) {
    if (!(d & (1 << i))) {
      continue;
    }

    ++cnt;
    for (ll a = 0; a < n; ++a) {
      for (ll b = 0; b < n; ++b) {
        for (ll mid = 0; mid < n; ++mid) {
          result[cnt][a][b] +=
              (result[cnt - 1][a][mid] * square[i][mid][b]) % INF;
          result[cnt][a][b] %= INF;
        }
      }
    }
  }

  cout << result[cnt][0][0] << "\n";

  return 0;
}