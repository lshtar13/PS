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

cll N = 200, K = 20;
ll n, k, cnt = -1, dp[K][N][N] = {{{}}};

ll search(ll color, ll st, ll en) {
  if (dp[color][st][en] != -1) {
    return dp[color][st][en];
  }
  ll result = N * K;

  for (ll mid = st; mid < en; ++mid) {
    result = min(result, search(color, st, mid) + search(color, mid + 1, en));
    for (ll c = 0; c < k; ++c) {
      result = min(result, search(c, st, mid) + search(c, mid + 1, en) + 1);
    }
  }

  return dp[color][st][en] = result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(dp, -1, sizeof(dp));
  cin >> n >> k;
  for (ll prv = 0, cur, i = 0; i < n; ++i) {
    cin >> cur;
    if (cur != prv) {
      ++cnt;
      dp[cur - 1][cnt][cnt] = 0;
      prv = cur;
    }
  }

  for (ll i = 0; i < cnt; ++i) {
    for (ll c = 0; c < k; ++c) {
      dp[c][i][i] *= -1;
    }
  }

  ll result = N * K;
  for (ll c = 0; c < k; ++c) {
    result = min(result, search(c, 0, cnt));
  }

  cout << result << "\n";

  return 0;
}