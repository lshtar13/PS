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

typedef tuple<ll, ll, ll> info_t;

cll N = 20, TIME = 2500;
ll n, ans[N][N] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR2(i, l, n, n) { cin >> ans[i][l]; }

  ll w, i, l, result = 0, nresult = 0, mat[N][N] = {{}};
  priority_queue<info_t, vector<info_t>, greater<info_t>> pq;
  memset(mat, -1, sizeof(mat));
  for (ll i = 0; i < n; ++i) {
    mat[i][i] = 0;
    for (ll l = i + 1; l < n; ++l) {
      pq.push({ans[i][l], i, l});
    }
  }

  while (!pq.empty()) {
    tie(w, i, l) = pq.top();
    pq.pop();

    if (mat[i][l] == ans[i][l]) {
      continue;
    } else if (w != ans[i][l]) {
      continue;
    }

    result += w, ++nresult;
    mat[i][l] = mat[l][i] = w;
    for (ll _i = 0; _i < n; ++_i) {
      for (ll _l = 0; _l < n; ++_l) {
        if (mat[_i][i] == -1 || mat[l][_l] == -1) {
          continue;
        } else if (mat[_i][i] + w + mat[l][_l] < ans[_i][_l]) {
          cout << -1 << "\n";
          return 0;
        } else if (mat[_i][i] + w + mat[l][_l] > ans[_i][_l]) {
          continue;
        }

        mat[_i][_l] = mat[_l][_i] = ans[_i][_l];
      }
    }
  }

  cout << result << "\n";

  return 0;
}