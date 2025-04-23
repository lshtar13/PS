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

typedef tuple<ll, ll, ll, ll> mat_t;

cll N = 1e18, MOD = 1e9 + 7;
ll n;

mat_t mult(mat_t a, mat_t b) {
  ll a0, a1, a2, a3, b0, b1, b2, b3;
  tie(a0, a1, a2, a3) = a, tie(b0, b1, b2, b3) = b;
  return {(a0 * b0 + a1 * b2) % MOD, (a0 * b1 + a1 * b3) % MOD,
          (a2 * b0 + a3 * b2) % MOD, (a2 * b1 + a3 * b3) % MOD};
}

mat_t fibo(ll num) {
  if (num == 0) {
    return {1, 0, 0, 1};
  } else if (num == 1) {
    return {1, 1, 1, 0};
  }

  mat_t a = fibo(num / 2), b = fibo(num % 2);
  return mult(mult(a, a), b);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  mat_t result = fibo(n);
  cout << (get<0>(result) * get<2>(result)) % MOD << "\n";

  return 0;
}