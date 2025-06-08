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

cll N = 50, STR = 1e3, ITN = 1e3, PNT = 1e3;
ll n, strs[N + 1] = {}, itns[N + 1] = {}, pnts[N + 1] = {},
               dp[STR + 1][ITN + 1] = {{}};

void find0(ll str, ll itn) {
  ll status = dp[str][itn];
  for (ll i = 0; i < n; ++i) {
    if (status & (1 << i)) {
      continue;
    } else if (strs[i] > str && itns[i] > itn) {
      continue;
    }

    
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> strs[i] >> itns[i] >> pnts[i];
  }

  find0(1, 1);

  return 0;
}