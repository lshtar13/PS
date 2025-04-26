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

cll N = 100, MOD = 1e6;
ll n, dp[N + 1][N + 1][2] = {{}};
// dp[a][b] cur 보다 작은 수 a개, 큰 수 b개로 만들 수 있는 것.

ll find0(ll a, ll b, ll c) {
  if (dp[a][b][c] != -1) {
    return dp[a][b][c];
  }

  ll &result = dp[a][b][c] = 0;
  if (c) {
    for (ll na = 0; na < a; ++na) {
      result = (result + find0(na, a + b - 1 - na, !c)) % MOD;
    }
  } else {
    for (ll nb = 0; nb < b; ++nb) {
      result = (result + find0(a + b - 1 - nb, nb, !c)) % MOD;
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = dp[0][0][1] = 1;
  if (n == 1) {
    cout << 1 << "\n";
  } else {
    cout << (find0(0, n, 0) + find0(n, 0, 1)) % MOD << "\n";
  }

  return 0;
}
