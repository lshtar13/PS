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

cll N = 3e3, COST = 1e3, NSPOT = 1e4;
ll n, dests[N + 1] = {}, truck, heli, dp[N + 2] = {}, prefixSum[N + 1] = {};
// dp[i] = i부터 ~ n까지 옮기는데 드는 비용 ...

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> dests[i];
  }
  cin >> truck >> heli;

  sort(dests + 1, dests + n + 1);

  for (ll i = 1; i <= n; ++i) {
    prefixSum[i] = prefixSum[i - 1] + dests[i];
  }

  for (ll i = n; i > 0; --i) {
    dp[i] = min(heli, truck * dests[i]) + dp[i + 1];
    for (ll l = i + 1, cost, mid, sum; l <= n; ++l) {
      mid = (i + l) / 2, cost = heli;
      cost += (dests[mid] * (mid - i + 1) - prefixSum[mid] + prefixSum[i - 1]) *
              truck;
      cost += (prefixSum[l] - prefixSum[mid] - dests[mid] * (l - mid)) * truck;
      dp[i] = min(dp[i], cost + dp[l + 1]);
    }
  }

  cout << dp[1] << '\n';

  return 0;
}