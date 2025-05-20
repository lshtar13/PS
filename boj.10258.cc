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

cll N = 31;
ll n, dp[N] = {};
bool status[N] = {};

ll find0(ll idx, bool tgt) {
  if (idx == n - 1) {
    return status[idx] != tgt;
  }

  if (status[idx] == tgt) {
    return find0(idx + 1, 0);
  } else {
    return find0(idx + 1, 1) + 1 + dp[n - 1 - idx];
  }
}

ll solve() {
  string str;
  cin >> str;
  n = str.size();
  for (ll i = 0; i < n; ++i) {
    status[i] = str[i] == '1';
  }

  ll result = 0;

  return find0(0, 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  dp[0] = 0;
  dp[1] = 1;
  for (ll i = 2; i < N; ++i) {
    dp[i] = 0;
    for (ll l = 0; l < i; ++l) {
      dp[i] += dp[l] + 1;
    }
  }

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}