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

cll N = 1e5, M = 100;
ll n, m, elevators[M][2] = {{}}, dp[M] = {};
bool avail[N][M] = {{}}, mat[M][M] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  cin >> n >> m;
  for (ll i = 0, x, y; i < m; ++i) {
    cin >> x >> y;
    elevators[i][0] = x, elevators[i][1] = y;
    for (ll floor = x; floor <= n; floor += y) {

      // check adjaceny
    }
  }

  return 0;
}