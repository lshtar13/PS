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

cll N = 1e6, M = 1e6;
ll n, m, nums[2 * N] = {}, p[2 * N] = {}, r = 0, c = 0;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[2 * i];
  }

  for (ll i = 1; i < 2 * n; ++i) {
    if (r < i) {
      p[i] = 0;
    } else {
      p[i] = min(p[2 * c - i], r - i);
    }

    while (i - p[i] - 1 >= 0 && i + p[i] + 1 < 2 * n) {
      if (nums[i - p[i] - 1] == nums[i + p[i] + 1]) {
        ++p[i];
      } else {
        break;
      }
    }

    if (r < i + p[i]) {
      c = i, r = i + p[i];
    }
  }

  cin >> m;
  for (ll i = 0, s, e, mid; i < m; ++i) {
    cin >> s >> e;
    s = (s - 1) * 2, e = (e - 1) * 2, mid = (s + e) / 2;
    if (mid - p[mid] <= s) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}