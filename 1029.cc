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

cll N = 15, PRICE = 10;
ll n, mat[N][N] = {{}}, dp[1 << 15][N][10];

ll solve(ll status, ll owner, ll cur) {
  if (dp[status][owner][cur] != -1) {
    return dp[status][owner][cur];
  }

  ll result = 0;
  for (ll buyer = 0; buyer < n; ++buyer) {
    if (status & (1 << buyer)) {
      continue;
    } else if (mat[owner][buyer] < cur) {
      continue;
    }

    result =
        max(result, solve(status | (1 << buyer), buyer, mat[owner][buyer]) + 1);
  }

  return dp[status][owner][cur] = result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    char c;
    for (ll l = 0; l < n; ++l) {
      cin >> c;
      mat[i][l] = c - '0';
    }
  }

  cout << solve(1, 0, 0) + 1 << "\n";

  return 0;
}