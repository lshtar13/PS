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

typedef tuple<ll, ll, ll, ll> mat;
double n;
mat genesis = {1, 1, 1, 0};

mat ffibo(double n) {
  if (n == 1) {
    return genesis;
  }

  ll a0, a1, a2, a3;
  tie(a0, a1, a2, a3) = ffibo(n / 2);
  return {a0 * a0 + a1 * a2, a0 * a1 + a1 * a3, a2 * a0 + a3 * a2,
          a2 * a1 + a3 * a3};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  n /= 2, n *= 2;

  ffibo(n);

  // Sn = f2n+1 - 1
  // 1 1
  // 1 0
  return 0;
}