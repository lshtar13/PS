#include <bits/stdc++.h>
#include <functional>
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

cll C = 20000, N = 20000;
ll c, n;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> c >> n;
  priority_queue<ll, vll, greater<ll>> chicks;
  priority_queue<pll, vector<pll>, greater<pll>> cows;
  for (ll i = 0, t; i < c; ++i) {
    cin >> t;
    chicks.push(t);
  }

  for (ll i = 0, a, b; i < n; ++i) {
    cin >> a >> b;
    cows.push({a, b - a});
  }

  while (!cows.empty()) {
    ll t = chicks.top(), st, len;
    tie(st, len) = cows.top();
    cows.pop();

    if (t < st) {
      chicks.pop();
    }
  }

  return 0;
}