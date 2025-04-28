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

cll T = 100, N = 20, D = 1e9, MOD = 1e9 + 7;
ll t, n, d;
vvll mat[T], nullMat, all;

vvll mult(const vvll &a, const vvll &b) {
  vvll result(n, vll(n, 0));
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      for (ll j = 0; j < n; ++j) {
        result[i][l] += a[i][j] * b[j][l];
        result[i][l] %= MOD;
      }
    }
  }

  return result;
}

vvll square(ll num) {
  if (num == 0) {
    return nullMat;
  }

  vvll result = square(num / 2);
  result = mult(result, result);
  if (num % 2) {
    result = mult(result, all);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> t >> n >> d;
  for (ll i = 0, m; i < t; ++i) {
    cin >> m;
    mat[i].resize(n, vll(n, 0));
    for (ll l = 0, a, b, c; l < m; ++l) {
      cin >> a >> b >> c;
      --a, --b;
      mat[i][a][b] = c;
    }
  }
  nullMat.resize(n, vll(n, 0));
  for (ll i = 0; i < n; ++i) {
    nullMat[i][i] = 1;
  }

  all = nullMat;
  for (ll i = 0; i < t; ++i) {
    all = mult(all, mat[i]);
  }

  vvll result = mult(square(d / t), nullMat);
  for (ll i = 0; i < d % t; ++i) {
    result = mult(result, mat[i]);
  }

  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cout << result[i][l] << " ";
    }
    cout << "\n";
  }

  return 0;
}