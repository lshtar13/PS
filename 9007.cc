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

cll N = 1000;
ll k, n, weights[4][N] = {{}}, sums[2][N * N] = {{}};

ll solve() {
  cin >> k >> n;
  FOR2(cls, stdnt, 4, n) { cin >> weights[cls][stdnt]; }

  for (ll i = 0, l; i < 2; ++i) {
    l = 0;
    FOR2(a, b, n, n) {
      sums[i][l++] = weights[i * 2][a] + weights[i * 2 + 1][b];
    }
  }

  sort(sums[0], sums[0] + n * n);
  sort(sums[1], sums[1] + n * n);

  ll idx0 = 0, idx1 = n * n - 1, sum, result = 1e9;
  while (idx0 < n * n && idx1 >= 0) {
    sum = sums[0][idx0] + sums[1][idx1];
    if (abs(k - result) > abs(k - sum)) {
      result = sum;
    } else if (abs(k - result) == abs(k - sum) && result > sum) {
      result = sum;
    }

    if (sum < k) {
      ++idx0;
    } else if (sum > k) {
      --idx1;
    } else {
      return sum;
    }
  }

  return result;
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