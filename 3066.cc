#include <algorithm>
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