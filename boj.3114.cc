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

cll R = 1500, C = 1500;
ll r, c, apples[R][C] = {{}}, bananas[R][C] = {{}}, sums[2][R][C] = {{{}}},
         dp[R][C] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  FOR2(i, l, r, c) {
    string tree;
    cin >> tree;

    ll size = stoi(tree.substr(1));
    if (tree[0] == 'B') {
      bananas[i][l] = size;
    } else {
      apples[i][l] = size;
    }
  }

  for (ll _c = 0; _c < c; ++_c) {
    sums[0][r - 1][_c] = 0;
    for (ll _r = r - 2; _r >= 0; --_r) {
      sums[0][_r][_c] = sums[0][_r + 1][_c] + apples[_r + 1][_c];
    }

    sums[1][0][_c] = 0;
    for (ll _r = 1; _r < r; ++_r) {
      sums[1][_r][_c] = sums[1][_r - 1][_c] + bananas[_r - 1][_c];
    }
  }

  for (ll l = c - 1; l >= 0; --l) {
    for (ll i = r - 1; i >= 0; --i) {
      if (i + 1 < r) {
        dp[i][l] = max(dp[i][l], dp[i + 1][l]);
      }

      if (l + 1 < c) {
        dp[i][l] =
            max(dp[i][l], dp[i][l + 1] + sums[0][i][l] + sums[1][i][l + 1]);
        if (i + 1 < r) {
          dp[i][l] = max(dp[i][l], dp[i + 1][l + 1] + sums[0][i][l] +
                                       sums[1][i + 1][l + 1]);
        }
      }
    }
  }
  cout << dp[0][0] << "\n";

  return 0;
}