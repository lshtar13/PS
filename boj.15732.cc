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

cll N = 1e6, K = 1e4, D = 1e9;
ll n, k, d, rules[K][3] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k >> d;
  for (ll i = 0; i < k; ++i) {
    cin >> rules[i][0] >> rules[i][1] >> rules[i][2];
  }

  ll st = 1, en = n, ans;

  while (st <= en) {
    ll mid = (st + en) / 2, cnt = 0;
    for (ll i = 0; i < k; ++i) {
      if (rules[i][0] > mid) {
        continue;
      }
      cnt += (min(rules[i][1], mid) - rules[i][0]) / rules[i][2] + 1;
    }

    if (d <= cnt) {
      ans = mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}