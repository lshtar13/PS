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

cll N = 4000;
ll n, A[N] = {}, B[N] = {}, C[N] = {}, D[N] = {}, AB[N * N] = {},
      CD[N * N] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
  }

  FOR2(i, l, n, n) {
    AB[i * n + l] = A[i] + B[l];
    CD[i * n + l] = C[i] + D[l];
  }

  sort(AB, AB + n * n);
  sort(CD, CD + n * n);

  ll result = 0, ab = n * n - 1, cd = 0;
  while (ab >= 0 && cd < n * n) {
    ll sum = AB[ab] + CD[cd], nab, ncd;
    if (sum == 0) {
      nab = 1, ncd = 1;
      while (ab - nab >= 0 && AB[ab] == AB[ab - nab]) {
        ++nab;
      }
      while (cd + ncd < n * n && CD[cd] == CD[cd + ncd]) {
        ++ncd;
      }
      result += nab * ncd, ab += nab, cd += ncd;
    } else if (sum < 0) {
      ++cd;
    } else {
      --ab;
    }
  }

  cout << result << "\n";

  return 0;
}