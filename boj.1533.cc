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
ll n, s, e, t, mat[N][N] = {{}};

ll find(ll src, ll dst, ll dur) {
  if (dur == 0) {
    if (src == dst) {
      return 1;
    } else {
      return 0;
    }
  } else if (dur < 0) {
    return 0;
  }
  cout << src << " " << dst << " " << dur << "\n";
  ll result = 0;
  for (ll i = 0; i < n; ++i) {
    if (mat[src][i]) {
      result += find(i, dst, dur - mat[src][i]);
      result %= MOD;
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> s >> e >> t;
  for (ll i = 0; i < n; ++i) {
    string input;
    cin >> input;
    for (ll l = 0; l < n; ++l) {
      mat[i][l] = input[l] - '0';
    }
  }

  cout << find(--s, --e, t) << "\n";

  return 0;
}