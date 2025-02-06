#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef const ll cll;

cll N = 1e4;
ll n, dp[N + 1] = {};
pll cords[N + 1];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> cords[i].first >> cords[i].second;
    cords[i].second = abs(cords[i].second);
  }
  sort(cords + 1, cords + n + 1);

  dp[0] = 0;
  for (ll i = 1; i <= n; ++i) {
    dp[i] = LLONG_MAX;
    for (ll maxHeight = 0, l = i - 1; l >= 0; --l) {
      maxHeight = max(maxHeight, cords[l + 1].second);
      dp[i] = min(dp[i], dp[l] + max(maxHeight * 2,
                                     cords[i].first - cords[l + 1].first));
    }
  }

  cout << dp[n] << "\n";

  return 0;
}