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

cll R = 750, C = 750, directions[4][2] = {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
ll r, c, diags[R][C][4];
bool mat[R][C] = {{}};
// 0, 1, 2, 3 clockwise

inline bool validCord(ll i, ll l) { return i >= 0 && i < r && l >= 0 && l < c; }

ll findDiag(ll i, ll l, ll d) {
  if (!validCord(i, l)) {
    return 0;
  } else if (diags[i][l][d] != -1) {
    return diags[i][l][d];
  }

  ll &result = diags[i][l][d], ni = i + directions[d][0],
     nl = l + directions[d][1];
  if (!mat[i][l]) {
    return result = 0;
  }

  result = 1;
  if (mat[ni][nl]) {
    result = max(result, findDiag(ni, nl, d) + 1);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  for (ll i = 0; i < r; ++i) {
    cin.ignore();
    for (ll l = 0; l < c; ++l) {
      char c;
      cin >> c;
      mat[i][l] = c - '0';
    }
  }

  
  memset(diags, -1, sizeof(diags));

  ll result = 0;
  for (ll i = 0; i < r; ++i) {
    for (ll l = 0; l < c; ++l) {
      if (!mat[i][l]) {
        continue;
      }

      ll maxSize = min(findDiag(i, l, 0), findDiag(i, l, 1));
      for (ll size = 1; size <= maxSize; ++size) {
        ll ni = i, nl = l + 2 * size - 2,
           nsize = min(findDiag(ni, nl, 2), findDiag(ni, nl, 3));

        if (size <= nsize) {
          result = max(result, size);
        }
      }
    }
  }

  cout << result << "\n";

  return 0;
}