#include <bits/stdc++.h>
#include <tuple>

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

typedef tuple<ll, ll, ll> tll;

cll N = 15, M = 15, D = 10;
ll n, m, d;
vpll enemies;

ll find(ll archers[]) {
  map<pll, ll> result;
  priority_queue<tll, vector<tll>, greater<tll>> pqs[3];

  for (const auto &e : enemies) {
    for (ll di = n - e.first, dl, idx = 0; idx < 3; ++idx) {
      dl = abs(archers[idx] - e.second);
      pqs[idx].push(make_tuple(di + dl, e.second, e.first));
    }
  }

  for (ll step = 0; step < n + 1; ++step) {
    ll dist, i, l;
    pll cords;
    for (auto &pq : pqs) {
    AGAIN:
      if (pq.empty()) {
        continue;
      }

      tie(dist, l, i) = pq.top();
      cords = make_pair(i, l);
      if (i + step >= n ||
          (result.find(cords) != result.end() && result[cords] < step)) {
        pq.pop();
        goto AGAIN;
      }
      if (dist > d + step) {
        continue;
      }

      pq.pop();
      result[cords] = step;
    }
  }

  return result.size();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> d;
  FOR2(i, l, n, m) {
    ll value;
    cin >> value;
    if (value) {
      enemies.emplace_back(make_pair(i, l));
    }
  }

  ll result = 0;
  for (ll i = 0; i < m; ++i) {
    for (ll l = i + 1; l < m; ++l) {
      for (ll j = l + 1; j < m; ++j) {
        ll archers[3] = {i, l, j};
        result = max(result, find(archers));
      }
    }
  }

  cout << result << '\n';

  return 0;
}