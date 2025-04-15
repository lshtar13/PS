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
cll N = 10000, INF = N * 10 + 1;
ll n, genesis[N + 1] = {}, goal[N] = {}, dp[N][10] = {{}};

ll find(ll idx, ll prv) {
  if (idx == n) {
    return 0;
  } else if (dp[idx][prv] != -1) {
    return dp[idx][prv];
  }

  ll &result = dp[idx][prv] = INF;
  for (ll cur = 0, nnum, right, turn, next; cur < 10; ++cur) {
    nnum = (genesis[idx] + prv + cur) % 10;
    right = (nnum - goal[idx] + 10) % 10;
    next = (prv + cur) % 10;
    turn = cur + right + find(idx + 1, next);
    result = min(result, turn);
  }

  return result;
}

void track(ll idx, ll prv) {
  if (idx == n) {
    return;
  }

  ll result = dp[idx][prv];
  for (ll cur = 0, nnum, right, turn, next; cur < 10; ++cur) {
    nnum = (genesis[idx] + prv + cur) % 10;
    right = (nnum - goal[idx] + 10) % 10;
    next = (prv + cur) % 10;
    turn = cur + right + find(idx + 1, next);

    if (turn == result) {
      if (cur) {
        cout << idx + 1 << " " << cur << "\n";
      }

      if (right) {
        cout << idx + 1 << " " << -right << "\n";
      }

      return track(idx + 1, next);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin.ignore();
  for (ll i = 0; i < n; ++i) {
    char c;
    cin >> c;
    genesis[i] = c - '0';
  }
  cin.ignore();
  for (ll i = 0; i < n; ++i) {
    char c;
    cin >> c;
    goal[i] = c - '0';
  }
  memset(dp, -1, sizeof(dp));

  cout << find(0, 0) << "\n";
  track(0, 0);

  return 0;
}