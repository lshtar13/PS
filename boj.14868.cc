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

cll N = 2000, K = 1e5, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, k, visited[N][N] = {{}}, civils[N][N] = {{}}, parents[K] = {};

inline bool validCord(ll x, ll y) { return x >= 0 && x < n && y >= 0 && y < n; }

ll findParent(ll node) {
  if (parents[node] == node) {
    return node;
  } else {
    return parents[node] = findParent(parents[node]);
  }
}

void merge(ll a, ll b) {
  ll parentA = findParent(a), parentB = findParent(b);
  parents[min(parentA, parentB)] = max(parentA, parentB);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(visited, -1, sizeof(visited));
  memset(civils, -1, sizeof(civils));
  qpll q0, q1;
  cin >> n >> k;
  for (ll i = 0, x, y; i < k; ++i) {
    cin >> x >> y;
    --x, --y;
    civils[x][y] = i, visited[x][y] = 0, parents[i] = i;
    q0.push({x, y});
    q1.push({x, y});
  }

  for (ll x, y, civil; !q0.empty();) {
    tie(x, y) = q0.front();
    q0.pop();

    civil = civils[x][y];
    for (auto &d : directions) {
      ll nx = x + d[0], ny = y + d[1], ncivil;
      if (!validCord(nx, ny)) {
        continue;
      }

      ncivil = civils[nx][ny];
      if (ncivil == -1) {
        civils[nx][ny] = civil;
        q0.push({nx, ny});
      }
    }
  }

  ll result = 0;
  for (ll x, y, civil; !q1.empty();) {
    tie(x, y) = q1.front();
    q1.pop();

    civil = civils[x][y];
    for (auto &d : directions) {
      ll nx = x + d[0], ny = y + d[1], ncivil;
      if (!validCord(nx, ny)) {
        continue;
      }

      ncivil = civils[nx][ny];
      if (ncivil == -1) {
        civils[nx][ny] = civil;
        q0.push({nx, ny});
      }
    }
  }

  cout << result << "\n";

  return 0;
}
