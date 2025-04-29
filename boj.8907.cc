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
ll n, result;
bool mat[N][N] = {{}};

ll solve() {
  cin >> n;
  memset(mat, 0, sizeof(mat));

  for (ll i = 0; i < n - 1; ++i) {
    for (ll l = i + 1; l < n; ++l) {
      cin >> mat[i][l];
      mat[l][i] = mat[i][l];
    }
  }

  ll num = 0;
  for (ll i = 0; i < n; ++i) {
    ll red = 0, blue = 0;
    for (ll l = 0; l < n; ++l) {
      if (l == i) {
        continue;
      }
      red += mat[i][l];
      blue += !mat[i][l];
    }

    num += red * blue;
  }

  return (n * (n - 1) * (n - 2)) / 6 - num / 2;
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