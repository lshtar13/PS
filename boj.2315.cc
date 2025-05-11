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

cll N = 1000, D = 1000, W = 1e8, INF = 1e9 + 1;
ll n, m, d, st, positions[N + 1] = {}, sum, sums[N + 1] = {},
                              dp[N + 1][N + 1][2] = {{{}}};

ll find0(ll left, ll right, bool isRight) {
  if (left < 1 || right > n) {
    return INF;
  } else if (dp[left][right][isRight] != -1) {
    return dp[left][right][isRight];
  } else if (left == 1 && right == n) {
    return dp[left][right][isRight] = 0;
  }

  ll &result = dp[left][right][isRight] = INF, dist,
     waste = sum - (sums[right] - sums[left - 1]);
  if (!isRight) {
    // left->right;
    if (right < n) {
      dist = positions[right + 1] - positions[left];
      result = min(result, find0(left, right + 1, true) + waste * dist);
    }

    // left->left;
    if (left > 1) {
      dist = positions[left] - positions[left - 1];
      result = min(result, find0(left - 1, right, false) + waste * dist);
    }
  } else {
    // right->left;
    if (left > 1) {
      dist = positions[right] - positions[left - 1];
      result = min(result, find0(left - 1, right, false) + waste * dist);
    }

    // right->right;
    if (right < n) {
      dist = positions[right + 1] - positions[right];
      result = min(result, find0(left, right + 1, true) + waste * dist);
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  sum = 0;
  for (ll i = 1, d, w; i <= n; ++i) {
    cin >> d >> w;
    positions[i] = d;
    sums[i] = sums[i - 1] + w, sum += w;
  }

  memset(dp, -1, sizeof(dp));
  cout << min(find0(m, m, 0), find0(m, m, 1)) << "\n";

  return 0;
}