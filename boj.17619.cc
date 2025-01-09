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

typedef tuple<ll, ll, ll, ll> info_t;

cll N = 1e5, INF = 1e9 + 1;
ll n;
deque<info_t> logs, prv;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll x1, x2, y, i = 0; i < n; ++i) {
    cin >> x1 >> x2 >> y;
    logs.emplace_back(make_tuple(x1, x2, y, i + 1));
  }

  sort(logs.begin(), logs.end());

  for (ll x1, x2, y, idx, i = 0; i < logs.size(); ++i) {
    tie(x1, x2, y, idx) = logs[i];

    ll topX, bottomX, topY, bottomY;
    for (ll _x1, _x2, _y, _idx, l = i + 1; l < logs.size(); ++l) {
      tie(_x1, _x2, _y, _idx) = logs[l];
      if (x2 < _x1) {
        break;
      }

      if

    }
  }

  return 0;
}