#include <bits/stdc++.h>
#include <functional>

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

cll N = 1e5, MAX_CORD = 1e9;
ll n;
map<ll, ll> buildings;

typedef tuple<ll, ll, ll> info_t;
priority_queue<info_t, vector<info_t>, greater<info_t>> pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll l, h, r, i = 0; i < n; ++i) {
    cin >> l >> h >> r;
    pq.push({l, r, h});
  }

  buildings[get<0>(pq.top())] = get<2>(pq.top());
  buildings[get<1>(pq.top())] = 0;
  pq.pop();

  for (ll l, r, h; !pq.empty(); pq.pop()) {
    tie(l, r, h) = pq.top();
    auto cur = buildings.lower_bound(l);
    if (cur == buildings.end()) {
      buildings[l] = h;
      buildings[r] = 0;
    } else {
      auto height = (--cur)->second;
      if (height < h) {
        buildings[l] = height;
      }

      vll del;
      for (auto it = buildings.lower_bound(l);
           it != buildings.end() && it->first < r; ++it) {
        if (it->second < h) {
          del.emplace_back(it->first);
        }
      }

      for (auto &d : del) {
        buildings.erase(d);
      }

      auto end = buildings.lower_bound(r);
      if((--end)->second)
    }
  }

  return 0;
}