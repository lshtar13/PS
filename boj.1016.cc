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

cll MIN = 1e12, MAX = MIN + 1e6, SQ = 1e6;
ll minN, maxN;
bool isNotPrime[SQ + 1] = {}, isNotOK[MAX - MIN + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> minN >> maxN;

  for (ll a, b, sq = 2; sq * sq <= maxN; ++sq) {
    if (isNotPrime[sq]) {
      continue;
    }

    for (ll num = 2 * sq; num <= SQ; num += sq) {
      isNotPrime[num] = true;
    }
    for (ll div = sq * sq, num = ((minN - 1) / div + 1) * div; num <= maxN;
         num += div) {
      isNotOK[num - minN] = true;
    }
  }

  ll result = 0;
  for (ll num = minN; num <= maxN; ++num) {
    result += !isNotOK[num - minN];
  }

  cout << result << "\n";

  return 0;
}