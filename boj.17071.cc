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

cll N = 5e5, K = 5e5, directions[3][2] = {{1, 1}, {1, -1}, {2, 0}};
ll n, k, mat[N + 1][2] = {};

inline bool isValidCord(ll idx) { return idx >= 0 && idx <= N; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  memset(mat, -1, sizeof(mat));
  qpll q;
  q.push({n, 0});
  mat[n][0] = 0;
  while (!q.empty()) {
    ll pos = q.front().first, isOdd = q.front().second;
    q.pop();

    for (auto &d : directions) {
      ll npos = pos * d[0] + d[1], nisOdd = !isOdd;
      if (isValidCord(npos) && mat[npos][nisOdd] == -1) {
        mat[npos][nisOdd] = mat[pos][isOdd] + 1;
        q.push({npos, nisOdd});
      }
    }
  }

  for (ll t = 0, pos = k + t; pos <= N; pos += ++t) {
    ll isOdd = t % 2;
    if (mat[pos][isOdd] == -1) {
      continue;
    }

    if (mat[pos][isOdd] <= t) {
      cout << t << "\n";
      goto END;
    }
  }

  cout << "-1\n";

END:

  return 0;
}