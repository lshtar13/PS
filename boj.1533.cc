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

cll N = 10, T = 1e9, MOD = 1e6 + 3;
ll n, st, en, t;
vvll mat1, mat2, mat;

vvll mult(vvll &a, vvll &b) {
  vvll result(n, vll(n, 0));
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      ll &value = result[i][l];
      for (ll j = 0; j < n; ++j) {
        value += a[i][j] * b[j][l];
        value %= MOD;
      }
    }
  }

  return result;
}

vvll nullMat(ll size) {
  vvll result(n, vll(n, 0));
  for (ll i = 0; i < n; ++i) {
    result[i][i] = 1;
  }

  return result;
}

vvll find1(ll s) {
  if (s == 0) {
    return nullMat(n);
  } else if (s == 1) {
    return mat1;
  }

  vvll result = find1(s / 2), find2(s / 2);
  result = mult(result, result);
  if (s % 2 == 1) {
    result = mult(result, mat1);
  } else {
    for ()
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> st >> en >> t;
  mat1 = vvll(n, vll(n, 0));
  mat2 = vvll(n, vll(n, 0));
  mat = vvll(n, vll(n, 0));
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < n; ++l) {
      char c;
      cin >> c;
      c = c - '0';
      if (c == 1) {
        mat1[l][i] = 1;
      } else if (c == 2) {
        mat2[l][i] = 1;
      }
    }
  }

  vvll final = findPath(t);

  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cout << final[i][l] << " ";
    }
    cout << "\n";
  }

  /*

0 0 1  1     0     0
1 0 0  0 ==> 1 ==> 0
0 1 0  0     0     1

0 1 0  1     0
0 0 1  0 ==> 0
1 0 0  0     1
*/

  return 0;
}