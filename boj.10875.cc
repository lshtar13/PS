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
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

typedef pair<pll, pll> cord_t;
vector<cord_t> cords;

cll T = 1e8, N = 1e3, directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
ll en, n;

inline bool isVertical(pll a, pll b) { return a.first == b.first; }

ll calcLine(pll a, pll b) {
  if (a > b) {
    swap(a, b);
  }

  for (auto &cord : cords) {
    pll na, nb;
    tie(na, nb) = cord;
    if (isVertical(a, b)) {
      // same(vert)
      if (isVertical(na, nb)) {
        if (na.first != a.first) {
          continue;
        }

        ll len = b.second - a.second;
        ll nlen = nb.second - na.second;
        ll total = max(b.second, nb.second) - min(a.second, na.second);
        if (total < len + nlen) {
          return;
        }
      } else {
        if (na.second < a.second || na.second > b.second) {
          continue;
        }

        return;
      }
    } else {
      // same(hor)
      if (!isVertical(na, nb)) {
        if (na.second != a.second) {
          continue;
        }

        ll len = b.first - a.first;
        ll nlen = nb.first - na.first;
        ll total = max(b.first, nb.first) - min(a.first, na.first);
        if (total < len + nlen) {
          return;
        }
      } else {
        if (na.second < a.second || na.second > b.second) {
          continue;
        }
      }
    }
  }

  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> en >> n;
  ++en;
  cords.emplace_back(-en, -en, en, -en);
  cords.emplace_back(-en, en, en, en);
  cords.emplace_back(en, -en, en, en);
  cords.emplace_back(-en, -en, -en, en);

  ll timeSum = 0;
  pll prv = {0, 0}, cur;
  for (ll i = 0, t, d = 2, line; i < n; ++i) {
    char dir;
    cin >> t;

    cur = {prv.first + t * directions[d][0], prv.second + t * directions[d][1]};
    line = calcLine(cur, prv);
    timeSum += line;

    if (line != t) {
      goto END;
    }

    cin.ignore();
    cin >> dir;
    if (dir == 'L') {
      d = (d + 3) % 4;
    } else {
      d = (d + 1) % 4;
    }
  }

END:
  cout << timeSum << "\n";

  return 0;
}