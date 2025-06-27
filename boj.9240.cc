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
typedef pair<pll, pll> ppll;
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 1e5, Cord = 1e3, Offset = 1e6;
ll n, hSize;
pll cords[N];

inline ll ccw(pll cord0, pll cord1, pll cord2) {
  return cord0.first * cord1.second + cord1.first * cord2.second +
         cord2.first * cord0.second - cord1.first * cord0.second -
         cord2.first * cord1.second - cord0.first * cord2.second;
}

inline ll ccw(ppll vec0, ppll vec1) {
  // 기준점 P1(x1, y1), P2(x2, y2), P3(x3, y3) 설정
  pll p1 = vec0.first;
  pll p2 = vec0.second;
  pll p3 = vec1.second;

  // 벡터 (P2-P1)와 (P3-P1)의 외적(cross product) 계산
  // S = (x2 - x1)(y3 - y1) - (y2 - y1)(x3 - x1)
  ll result = (p2.first - p1.first) * (p3.second - p1.second) -
              (p2.second - p1.second) * (p3.first - p1.first);

  return result;
}

inline bool cmp0(pll &a, pll &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

inline bool cmp1(pll &a, pll b) { return ccw(cords[0], a, b) > 0; }

inline double dist(pll &a, pll &b) {
  double result = sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
  //  return round(result * Offset) / Offset;
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) { cin >> cords[i].first >> cords[i].second; }
  sort(cords, cords + n, cmp0);
  sort(cords + 1, cords + n, cmp1);

  deque<pll> hull;
  FOR(i, n) {
    hSize = hull.size();
    while (hSize >= 2 && ccw(hull[hSize - 2], hull[hSize - 1], cords[i]) <= 0) {
      hull.pop_back();
      hSize = hull.size();
    }

    hull.emplace_back(cords[i]);
  }

  hSize = hull.size();
  double result = 0;
  ll a = 0, b, c = 1, d;
  while (a < hSize) {
    result = max(result, dist(hull[a], hull[c]));
    b = (a + 1) % hSize, d = (c + 1) % hSize;
    if (ccw({hull[a], hull[b]}, {hull[c], hull[d]}) > 0) {
      c = (c + 1) % hSize;
    } else {
      ++a;
    }
  }

  cout.precision(15);
  cout << result << "\n";

  return 0;
}