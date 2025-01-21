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

cll N = 3000;
ll a, b, c, len[2], dp[N + 1][N + 1] = {{}};
char str[2][N + 1];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;
  cin >> str[0] >> str[1];
  len[0] = strlen(str[0]), len[1] = strlen(str[1]);

  dp[len[0]][len[1]] = 0;
  for (ll idx = len[0] - 1; idx >= 0; --idx) {
    dp[idx][len[1]] = b * (len[0] - idx);
  }
  for (ll idx = len[1] - 1; idx >= 0; --idx) {
    dp[len[0]][idx] = b * (len[1] - idx);
  }

  for (ll i = len[0] - 1; i >= 0; --i) {
    for (ll l = len[1] - 1; l >= 0; --l) {
      dp[i][l] = max(dp[i + 1][l] + b, dp[i][l + 1] + b);
      if (str[0][i] == str[1][l]) {
        dp[i][l] = max(dp[i][l], dp[i + 1][l + 1] + a);
      } else {
        dp[i][l] = max(dp[i][l], dp[i + 1][l + 1] + c);
      }
    }
  }

  cout << dp[0][0] << "\n";

  return 0;
}