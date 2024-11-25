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

cll N = 10, M = 300, H = 30;
ll n, m, h;
bool mat[N][H] = {{}};

ll find(ll idx) {
  ll i = idx / h, l = idx % h, result = M;
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> h;
  for (ll a, b, i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    mat[b][a] = true;
  }

  for (ll i = 0, sum = 0; i < n - 1; ++i) {
    for (ll l = 0; l < h; ++l) {
      sum += mat[i][l];
    }

    if (sum % 2) {
      cout << -1 << "\n";
      goto END;
    }
  }

END:
  return 0;
}