#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef const ll cll;
typedef vector<ll> vll;

cll N = 40000;
ll ports[N], dp[N];

ll solve(ll n) {
  vll lis;
  for (ll p, i = 0; i < n; ++i) {
    cin >> p;
    auto it = upper_bound(lis.begin(), lis.end(), p);
    if (it == lis.end()) {
      lis.emplace_back(p);
    } else {
      *it = p;
    }
  }

  return lis.size();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    cout << solve(n) << "\n";
  }

  return 0;
}