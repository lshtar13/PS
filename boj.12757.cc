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

cll N = 1e5, M = 1e5, K = 1e5, INF = 1e9 + 1;
ll n, m, limit;
map<ll, ll> db;

ll find(ll k) {
  auto it = db.lower_bound(k);
  if (it == db.end()) {
    --it;
    if (it->first < k && k - it->first > limit)
      return -2;
  } else if (it == db.begin()) {
    if (it->first > k && it->first - k > limit)
      return -2;
  } else {
    auto lower = prev(it);
    if (it->first - k > limit && k - lower->first > limit)
      return -2;
    if (k - lower->first < it->first - k)
      it = lower;
    else if (k - lower->first == it->first - k)
      return -1;
  }

  return it->first;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> limit;
  for (ll k, v, i = 0; i < n; ++i) {
    cin >> k >> v;
    db[k] = v;
  }

  for (ll cmd, k, v, key, i = 0; i < m; ++i) {
    cin >> cmd >> k;
    if (cmd == 1) {
      cin >> v;
      db[k] = v;
    }
    if (cmd == 2) {
      cin >> v;
      key = find(k);
      if (key >= 0) {
        db[key] = v;
      }
    }
    if (cmd == 3) {
      key = find(k);
      if (key >= 0) {
        cout << db[key] << "\n";
      } else if (key == -1) {
        cout << "?" << "\n";
      } else {
        cout << "-1" << "\n";
      }
    }
  }

  return 0;
}