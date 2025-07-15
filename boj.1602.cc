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

cll N = 500, M = 1e4, Q = 4e4, D = 1e4, INF = 1e9;
ll n, m, q, mat[N][N] = {{}}, results[N][N] = {{}}, idxs[N] = {};
pll delayed[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(mat, 0x3f3f3f3f, sizeof(mat));
  memset(results, 0x3f3f3f3f, sizeof(results));
  cin >> n >> m >> q;
  FOR(i, n) {
    cin >> delayed[i].first;
    delayed[i].second = i;
  }
  sort(delayed, delayed + n);
  FOR(i, n) {
    idxs[delayed[i].second] = i;
    mat[i][i] = 0;
  }
  FOR(i, m) {
    ll a, b, d;
    cin >> a >> b >> d;
    a = idxs[a - 1], b = idxs[b - 1];
    mat[a][b] = min(mat[a][b], d), mat[b][a] = min(mat[b][a], d);
  }

  FOR(d, n) {
    FOR(a, n) FOR(b, n) { mat[a][b] = min(mat[a][b], mat[a][d] + mat[d][b]); }

    FOR(a, d + 1) FOR(b, d + 1) {
      results[a][b] =
          min(results[a][b], mat[a][d] + mat[d][b] + delayed[d].first);
    }
  }

  FOR(i, q) {
    ll s, t;
    cin >> s >> t;
    s = idxs[s - 1], t = idxs[t - 1];

    if (results[s][t] > INF) {
      cout << "-1\n";
    } else {
      cout << results[s][t] << "\n";
    }
  }

  return 0;
}