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

cll N = 250, M = 31250;
ll n, m, k;
ull arr[N][N] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  memset(arr, -1, sizeof(arr));
  for (ll i = 0; i < n; ++i) {
    arr[i][i] = 0;
  }
  for (ll u, v, b, i = 0; i < m; ++i) {
    cin >> u >> v >> b;
    --u, --v;
    if (b) {
      arr[u][v] = arr[v][u] = 0;
    } else {
      arr[u][v] = 0, arr[v][u] = 1;
    }
  }

  for (ll node = 0; node < n; ++node) {
    FOR2(a, b, n, n) {
      if (arr[a][node] == -1 || arr[node][b] == -1) {
        continue;
      }

      arr[a][b] = min(arr[a][b], arr[a][node] + arr[node][b]);
    }
  }

  cin >> k;
  for (ll s, e; k--;) {
    cin >> s >> e;
    --s, --e;
    cout << arr[s][e] << "\n";
  }

  return 0;
}