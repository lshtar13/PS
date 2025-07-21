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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)

cll N = 1000, Time = 100;
ll n, oven[N][2] = {{}}, dp[2][Time] = {{}};

ll solve() {
  cin >> n;
  memset(dp, -1, sizeof(dp));
  dp[1][0][0] = dp[1][1][0] = 0;
  FOR(i, 0, n) {
    ll a, b, cur = i % 2, prv = (i + 1) % 2;
    cin >> a >> b;

    dp[]
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}