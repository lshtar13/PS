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

cll N = 1e5;
ll n, pi[N] = {};
string strA, strB;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> strA >> strB;
  n = strA.size();

  for (ll i = 1, prv = pi[0]; i < n; ++i) {
    while (prv && strA[i] != strA[prv]) {
      prv = pi[prv - 1];
    }

    prv = pi[i] = (strA[i] == strA[prv] ? prv + 1 : 0);
  }

  strB = strB + strB;
  ll result = 0, a = 0, b = 0;
  while (b < 2 * n - 1) {
    if (strA[a] == strB[b]) {
      ++a, ++b;
    } else if (a) {
      a = pi[a - 1];
    } else {
      ++b;
    }

    if (a == n) {
      ++result, a = pi[n - 1];
    }
  }

  cout << result << "\n";

  return 0;
}