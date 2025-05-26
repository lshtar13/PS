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

cll N = 14, M = 14, CLASS = 5;
cll values[CLASS][CLASS] = {{10, 8, 7, 5, 1},
                            {8, 6, 4, 3, 1},
                            {7, 4, 3, 2, 1},
                            {5, 3, 2, 2, 1},
                            {1, 1, 1, 1, 0}};
ll n, m, mat[N][M] = {{}};
bool checked[N][M] = {{}};

ll findMax(ll idx) {
  ll i = idx / m, l = idx % m;
  if (idx >= n * m) {
    return 0;
  } else if (checked[i][l]) {
    return findMax(idx + 1);
  }

  ll result = 0;
  checked[i][l] = true;
  // 한칸
  result = max(result, findMax(idx + 1));
  // 오른쪽
  if (l + 1 < m) {
    checked[i][l + 1] = true;
    result = max(result, findMax(idx + 1) + values[mat[i][l]][mat[i][l + 1]]);
    checked[i][l + 1] = false;
  }
  // 아래쪽
  if (i + 1 < n) {
    checked[i + 1][l] = true;
    result = max(result, findMax(idx + 1) + values[mat[i][l]][mat[i + 1][l]]);
    checked[i + 1][l] = false;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < m; ++l) {
      char c;
      cin >> c;
      mat[i][l] = c - 'A';
      if (mat[i][l] == CLASS) {
        --mat[i][l];
      }
    }
  }

  cout << findMax(0) << "\n";

  return 0;
}