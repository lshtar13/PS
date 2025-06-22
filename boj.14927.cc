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

cll N = 18, Status = 1 << N;
ll n, status[N + 1] = {};

ull check(ll click) {
  ull prv = 0, cur = 0, next = 0, result = 0;
  cur = status[0], next = status[1];
  FOR(i, n) {
    if (click & (1 << (i + 1))) {
      cur ^= (1 << i), cur ^= (1 << (i + 1)), cur ^= (1 << (i + 2));
      next ^= (1 << (i + 1)), ++result;
    }
  }

  for (ll line = 1; line < n; ++line) {
    prv = cur, cur = next, next = status[line + 1];
    for (ll i = 0; i < n; ++i) {
      if (prv & (1 << (i + 1))) {
        cur ^= (1 << i), cur ^= (1 << (i + 1)), cur ^= (1 << (i + 2));
        next ^= (1 << (i + 1)), ++result;
      }
    }
  }

  cur >>= 1, cur &= (1 << n) - 1;
  if (cur) {
    return -1;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) FOR(l, n) {
    bool clicked;
    cin >> clicked;
    status[i] |= (clicked << (l + 1));
  }

  ull result = -1;
  FOR(click, 1 << (n)) { result = min(result, check(click << 1)); }
  cout << (ll)result << "\n";

  return 0;
}