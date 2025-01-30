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

cll N = 1000, neighbors[4] = {-2, -1, 1, 2};

ll solve() {
  ll n, heights[N], result = 0;
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> heights[i];
  }

  for (ll i = 2; i < n - 2; ++i) {
    ll top = 0;
    for (auto &neighbor : neighbors) {
      top = max(top, heights[i + neighbor]);
    }

    result += heights[i] - min(heights[i], top);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (ll t = 0; t < 10; ++t) {
    cout << "#" << t + 1 << " " << solve() << "\n";
  }
  return 0;
}