#include <bits/stdc++.h>
#include <string>

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

cll W = 30, H = 30, INF = 987654321,
    directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll w, h, g, e, minDist[W * H] = {}, dst;
bool graves[W][H] = {{}}, holes[W][H] = {{}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < w && l >= 0 && l < h && !graves[i][l];
}

string solve() {
  vector<info_t> edges;
  memset(graves, 0, sizeof(graves));
  memset(holes, 0, sizeof(holes));

  cin >> g;
  for (ll i = 0, x, y; i < g; ++i) {
    cin >> x >> y;
    graves[x][y] = true;
  }

  cin >> e;
  for (ll i = 0, x1, y1, x2, y2, t; i < e; ++i) {
    cin >> x1 >> y1 >> x2 >> y2 >> t;
    holes[x1][y1] = true;
    edges.emplace_back(x1 * h + y1, x2 * h + y2, t);
  }

  dst = h * w - 1;
  for (ll i = 0; i < w; ++i) {
    for (ll l = 0; l < h; ++l) {
      if (holes[i][l] || graves[i][l]) {
        continue;
      } else if (i * h + l == dst) {
        continue;
      }

      for (auto &d : directions) {
        ll ni = i + d[0], nl = l + d[1];
        if (!isValidCord(ni, nl)) {
          continue;
        }

        edges.emplace_back(i * h + l, ni * h + nl, 1);
      }
    }
  }

  fill(minDist, minDist + H * W, INF);
  minDist[0] = 0;
  for (ll node = 0; node < h * w; ++node) {
    for (auto &edge : edges) {
      ll from, to, t, prv;
      tie(from, to, t) = edge;

      if (minDist[from] == INF) {
        continue;
      }

      prv = minDist[to];
      minDist[to] = min(minDist[to], minDist[from] + t);

      if (node == dst && prv > minDist[to]) {
        return "Never";
      }
    }
  }

  if (minDist[dst] == INF) {
    return "Impossible";
  } else {
    return to_string(minDist[dst]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (; cin >> w >> h && w && h;) {
    cout << solve() << "\n";
  }

  return 0;
}