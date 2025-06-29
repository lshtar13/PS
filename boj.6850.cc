#include <algorithm>
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
#define FOR(a, A) for (ll a = 0; a < A; ++a)
typedef pair<pll, pll> vec;

cll N = 1e4;
ll n;
pll cords[N];

inline ll ccw(pll &a, pll &b, pll &c) {
  return a.first * b.second + b.first * c.second + c.first * a.second -
         b.first * a.second - c.first * b.second - a.first * c.second;
}

inline bool cmp0(pll &a, pll &b) {
  if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

inline bool cmp1(pll &a, pll &b) {
  ll value = ccw(cords[0], a, b);
  if (value) {
    return value > 0;
  } else if (a.second == b.second) {
    return a.first < b.first;
  } else {
    return a.second < b.second;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) { cin >> cords[i].first >> cords[i].second; }
  swap(*cords, *min_element(cords, cords + n, cmp0));
  sort(cords + 1, cords + n, cmp1);

  vpll hull;
  FOR(i, n) {
    while (hull.size() >= 2 &&
           ccw(hull[hull.size() - 2], hull[hull.size() - 1], cords[i]) <= 0) {
      hull.pop_back();
    }
    hull.push_back(cords[i]);
  }

  ll result = 0, size = hull.size();
  FOR(i, size) { result += ccw(hull[0], hull[i], hull[(i + 1) % size]); }
  cout << result / 100 << "\n";

  return 0;
}