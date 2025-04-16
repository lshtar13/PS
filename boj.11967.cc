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

cll N = 100, M = 20000, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m;
bool visited[N][N] = {{}}, isLighted[N][N] = {{}};
vpll mat[N][N];

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll x, y, a, b, i = 0; i < m; ++i) {
    cin >> x >> y >> a >> b;
    --x, --y, --a, --b;
    mat[x][y].emplace_back(a, b);
  }

  ll result = 1;
  qpll q;
  q.push({0, 0});
  visited[0][0] = true, isLighted[0][0] = true;
  for (ll i, l; !q.empty();) {
    tie(i, l) = q.front();
    q.pop();

    for (auto &d : directions) {
      ll ni = i + d[0], nl = l + d[1];
      if (!isValidCord(ni, nl)) {
        continue;
      }

      if (!visited[ni][nl]) {
        visited[ni][nl] = true;
        if (isLighted[ni][nl]) {
          q.push({ni, nl});
        }
      }
    }

    for (auto &p : mat[i][l]) {
      if (isLighted[p.first][p.second]) {
        continue;
      }

      ++result;
      isLighted[p.first][p.second] = true;
      if (visited[p.first][p.second]) {
        q.push({p.first, p.second});
      }
    }
  }

  cout << result << "\n";

  return 0;
}