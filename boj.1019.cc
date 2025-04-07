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

cll N = 1e9;
ll n, cnts[10] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll value = 0; value < 10; ++value) {
    for (ll digit = 0; digit < 10; ++digit) {
      ll base = pow(10, digit), upper = (n / base) / 10, lower = n % base;
      if (base * value <= n) {
        cnts[value] += (upper + 1) * (lower + 1);
      }
    }
  }

  for (ll value = 0; value < 10; ++value) {
    cout << cnts[value] << " ";
  }
  cout << "\n";

  return 0;
}