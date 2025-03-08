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

cll N = 15, LEN = 50 * 15 + 1, K = 100, STATUS = (1 << 15);
ll n, k, nums[N] = {}, cases[STATUS][K] = {{}}, length[STATUS] = {}, power[LEN],
         fact[N + 1] = {};
// i번째를 맨 앞에 두었을 경우로 나누어 계산 ...
string numstr[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> numstr[i];
  }
  cin >> k;

  power[0] = 1;
  for (ll p = 1; p < LEN; ++p) {
    power[p] = (power[p - 1] * 10) % k;
  }

  fact[0] = 1;
  for (ll i = 1; i <= N; ++i) {
    fact[i] = fact[i - 1] * i;
  }

  for (ll i = 0; i < n; ++i) {
    for (auto c : numstr[i]) {
      nums[i] = (nums[i] * 10 + c - '0') % k;
    }
  }

  for (ll status = 0; status < (1 << n); ++status) {
    for (ll i = 0; i < n; ++i) {
      if (status & (1 << i)) {
        length[status] += numstr[i].size();
      }
    }
  }

  cases[0][0] = 1;
  for (ll status = 1; status < (1 << n); ++status) {
    for (ll nstatus, num, i = 0; i < n; ++i) {
      if (!(status & (1 << i))) {
        continue;
      }

      nstatus = status & (~(1 << i));
      for (ll r = 0, nr; r < k; ++r) {
        nr = (r + ll(power[length[nstatus]]) * nums[i]) % k;
        cases[status][nr] += cases[nstatus][r];
      }
    }
  }
  ll result = cases[(1 << n) - 1][0], div = gcd(fact[n], result);
  cout << cases[(1 << n) - 1][0] / div << "/" << fact[n] / div << "\n";

  return 0;
}