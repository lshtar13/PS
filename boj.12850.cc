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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll D = 1e9, Mod = 1e9 + 7;
vvll mat = {{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 1, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 0, 1, 0, 0}, {0, 1, 1, 0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0, 1, 1, 0}, {0, 0, 1, 1, 1, 0, 0, 1},
            {0, 0, 0, 0, 1, 0, 0, 1}, {0, 0, 0, 0, 0, 1, 1, 0}},
     identity = {{1, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 0, 0, 0, 0},
                 {0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 0},
                 {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0},
                 {0, 0, 0, 0, 0, 0, 1, 0}, {0, 0, 0, 0, 0, 0, 0, 1}};
ll d;

vvll mult0(vvll &a, vvll &b) {
  vvll result(8, vll(8, 0));
  FOR(i, 8) FOR(l, 8) {
    FOR(j, 8) { result[i][l] += a[i][j] * b[j][l], result[i][l] %= Mod; }
  }

  return result;
}

vvll mult(ll d) {
  if (d == 0) {
    return identity;
  }

  vvll result = mult(d / 2);
  result = mult0(result, result);
  if (d % 2) {
    result = mult0(result, mat);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> d;
  vvll result = mult(d);
  cout << result[0][0] << "\n";

  return 0;
}