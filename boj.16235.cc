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

cll N = 10, M = 100, K = 1000,
    directions[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                        {0, 1},   {1, -1}, {1, 0},  {1, 1}};
ll n, m, k, nourish[N][N] = {{}}, A[N][N] = {{}};

inline bool isValid(ll i, ll l) { return i >= 0 && i < n && l >= 0 && l < n; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  FOR2(i, l, n, n) {
    cin >> A[i][l];
    nourish[i][l] = 5;
  }

  typedef pair<ll, pll> info;
  deque<info> trees, dead, alive;

  for (ll x, y, z, i = 0; i < m; ++i) {
    cin >> x >> y >> z;
    trees.emplace_back(make_pair(z, make_pair(--x, --y)));
  }

  FOR1(year, k) {
    // spring
    for (ll i = 0; i < trees.size(); ++i) {
      ll x = trees[i].second.first, y = trees[i].second.second,
         z = trees[i].first;
      if (nourish[x][y] < z) {
        dead.emplace_back(make_pair(z / 2, make_pair(x, y)));
        --i;
        trees.erase(trees.begin() + i + 1);
      } else {
        nourish[x][y] -= z;
        trees[i].first += 1;
      }
    }

    // summer
    for (auto &d : dead) {
      ll x = d.second.first, y = d.second.second, z = d.first;
      nourish[x][y] += z;
    }
    dead.clear();

    // autum
    for (ll i = 0; i < trees.size(); ++i) {
      ll x = trees[i].second.first, y = trees[i].second.second,
         z = trees[i].first;

      if (z % 5 != 0) {
        continue;
      }

      for (auto &d : directions) {
        ll _x = x + d[0], _y = y + d[1];

        if (isValid(_x, _y)) {
          ++i;
          trees.emplace_front(make_pair(1, make_pair(_x, _y)));
        }
      }
    }

    // winter
    FOR2(i, l, n, n) { nourish[i][l] += A[i][l]; }
  }

  cout << trees.size() << "\n";

  return 0;
}