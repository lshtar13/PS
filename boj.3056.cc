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

cll N = 20, STATUS = 1 << N;
ll n;
double probs[N][N] = {{}}, dp[STATUS] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> probs[i][l];
      probs[i][l] /= 100;
    }
  }

  dp[0] = 1;
  for (ll status = 1, mission; status < (1 << n); ++status) {
    mission = -1;
    for (ll bond = 0; bond < n; ++bond) {
      if (status & (1 << bond)) {
        ++mission;
      }
    }

    for (ll bond = 0, cur, prv; bond < n; ++bond) {
      cur = (1 << bond), prv = status ^ cur;
      if (!(status & cur)) {
        continue;
      }

      dp[status] = max(dp[status], probs[bond][mission] * dp[prv]);
    }
  }

  cout << fixed;
  cout.precision(6);
  cout << dp[(1 << n) - 1] * 100 << "\n";

  return 0;
}