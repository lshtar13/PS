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

cll N = 15, PRICE = 10, INF = 1000;
ll n, mat[N][N] = {{}};
vvll dp(1 << 15, vll(N, INF));

void solve(ll status, ll last_owner) {
  for (ll _status, buyer = 0; buyer < n; ++buyer) {
    if (status & buyer) {
      continue;
    } else if (mat[last_owner][buyer] < dp[status][last_owner]) {
      continue;
    }
    _status = status | (1 << buyer);

    dp[_status][buyer] = min(dp[_status][buyer], mat[last_owner][buyer]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    char c;
    for (ll l = 0; l < n; ++l) {
      cin >> c;
      mat[i][l] = c - '0';
    }
  }

  dp[1][0] = 0;
  solve(1, 0);

  return 0;
}