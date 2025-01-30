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

cll N = 1e5, X = 1e9;
ll n, cords[N] = {};

ull calcDist(ll term) {
  ull dist = 0;
  for (ll i = 0; i < n; ++i) {
    dist += abs(i * term - cords[i]);
  }

  return dist;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> cords[i];
  }

  ll st = 1, en = X;
  while (en - st >= 3) {
    ll sse = (st * 2 + en) / 3, see = (st + en * 2) / 3;

    if (calcDist(sse) < calcDist(see)) {
      en = see;
    } else {
      st = sse;
    }
  }

  ull ans = LLONG_MAX;
  for (ll term = st; term <= en; ++term) {
    ans = min(ans, calcDist(term));
  }

  cout << ans << "\n";

  return 0;
}