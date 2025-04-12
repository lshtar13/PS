#include <bits/stdc++.h>
#include <queue>

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

cll N = 1e5, H = 1e8, O = 1e8, D = 2e8;
ll n, d;
pll locations[N];

inline ll len(pll &location) { return location.second - location.first; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  priority_queue<pll, vector<pll>, greater<pll>> pq;

  cin >> n;
  for (ll i = 0, h, o; i < n; ++i) {
    cin >> h >> o;
    locations[i] = {min(h, o), max(h, o)};
    pq.push({locations[i].second, locations[i].first});
  }
  cin >> d;

  sort(locations, locations + n);

  ll idx = 0, cnt = 0, result = 0;
  while (idx < n) {
    if (len(locations[idx]) > d) {
      ++idx;
      continue;
    }

    while (!pq.empty()) {
      ll st, en;
      tie(en, st) = pq.top();
      if (en > locations[idx].first + d) {
        break;
      }

      pq.pop();
      if (st < locations[idx].first) {
        continue;
      }
      ++cnt;
    }

    result = max(result, cnt);
    ++idx, --cnt;
  }

  cout << result << "\n";

  return 0;
}