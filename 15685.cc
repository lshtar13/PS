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

cll N = 20, directions[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
ll n;
bool mat[101][101] = {{}}; // x , y

void turn(vpll &cords) {
  pll pt = cords.back();
  for (auto it = cords.begin() + cords.size() - 2; it >= cords.begin(); --it) {
    ll dx = pt.first - it->first, dy = pt.second - it->second, swp;
    swp = -dx, dx = dy, dy = swp;
    cords.emplace_back(make_pair(pt.first + dx, pt.second + dy));
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll x, y, d, g; n--;) {
    vpll cords;
    cin >> x >> y >> d >> g;
    cords.emplace_back(make_pair(x, y));
    cords.emplace_back(make_pair(x + directions[d][0], y + directions[d][1]));
    for (ll _g = 0; _g < g; ++_g) {
      turn(cords);
    }

    for (auto &p : cords) {
      if (p.first < 0 || p.first > 100 || p.second < 0 || p.second > 100) {
        continue;
      }
      mat[p.first][p.second] = true;
    }
  }

  ll result = 0;
  for (ll x = 0; x < 100; ++x) {
    for (ll y = 0; y < 100; ++y) {
      if (!mat[x][y]) {
        continue;
      } else if (!mat[x + 1][y]) {
        continue;
      } else if (!mat[x][y + 1]) {
        continue;
      } else if (!mat[x + 1][y + 1]) {
        continue;
      }

      ++result;
    }
  }

  cout << result << "\n";

  return 0;
}