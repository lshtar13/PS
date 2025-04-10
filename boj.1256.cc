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

cll N = 100, M = 100, K = 1e9;
ll nstr[N + 1][M + 1] = {{}};

void solve(ll n, ll m, ll k) {
  if (n > 0 && nstr[n - 1][m] >= k) {
    cout << "a";
    solve(n - 1, m, k);
  } else if (m > 0) {
    cout << "z";
    solve(n, m - 1, k - nstr[n - 1][m]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (ll a = 0; a <= N; ++a) {
    nstr[a][0] = 1;
  }
  for (ll b = 0; b <= N; ++b) {
    nstr[0][b] = 1;
  }

  for (ll a = 1; a <= N; ++a) {
    for (ll b = 1; b <= M; ++b) {
      nstr[a][b] = nstr[a - 1][b] + nstr[a][b - 1];
      if (nstr[a][b] > K) {
        nstr[a][b] = K + 1;
      }
    }
  }

  ll n, m, k;
  cin >> n >> m >> k;
  if (nstr[n][m] < k) {
    cout << "-1";
  } else {
    solve(n, m, k);
  }

  return 0;
}