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

cll divs[6] = {1, 10, 100, 1000, 10000, 100000};
ll dp[1000000][10] = {{}};

ll change(ll num, ll a, ll b) {
  ll numA = (num / divs[a]) % 10, numB = (num / divs[b]) % 10;
  num -= numA * divs[a] + numB * divs[b];
  num += numA * divs[b] + numB * divs[a];

  return num;
}

ll maxFind(ll num, cll ndigit, ll nchange, ll dp[][10]) {
  if (dp[num][nchange]) {
    return dp[num][nchange];
  } else if (nchange == 0) {
    return num;
  }

  ll result = 0;
  for (ll i = 0; i <= ndigit; ++i) {
    for (ll l = i + 1; l <= ndigit; ++l) {
      result = max(result, maxFind(change(num, i, l), ndigit, nchange - 1, dp));
    }
  }

  return dp[num][nchange] = result;
}

ll solve() {
  ll num, nchange, ndigit = 0;
  cin >> num >> nchange;
  for (ll k = 10; num >= k; k *= 10) {
    ++ndigit;
  }
  return maxFind(num, ndigit, nchange, dp);
}

int main(void) {
  ll t;
  cin >> t;
  for (ll i = 1; i <= t; ++i) {
    printf("#%lld %lld\n", i, solve());
  }

  return 0;
}