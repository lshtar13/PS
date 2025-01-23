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

cll U = 2e9;
ll l, u, result = 0;

bool find(ll prefix, ll suffix, ll preSum) {
  ll num = prefix * 10 + suffix, sum = preSum + suffix;
  if (num > u) {
    return false;
  } else if (num >= l) {
    result += sum;
  }

  for (ll digit = 0; digit < 10 && find(num, digit, sum); ++digit) {
  }

  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> l >> u;

  return 0;
}