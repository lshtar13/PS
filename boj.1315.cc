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

cll N = 50, STR = 1000, INR = 1000, PNT = 1000;
ll n, strs[N] = {}, inrs[N] = {}, pnts[N] = {}, dp[STR + 1][INR + 1] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) { cin >> strs[i] >> inrs[i] >> pnts[i]; }

  memset(dp, -1, sizeof(dp));
  dp[1][1] = 0;
  FOR(qidx, n) {
    ll str = strs[qidx], inr = inrs[qidx];
    FOR(pstr, STR) FOR(pinr, INR) {
      if (pstr >= str || pinr >= inr) {
        dp[pstr+]
      }
    }
  }

  return 0;
}