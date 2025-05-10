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

cll N = 2e5, MOD = 360;
ll n, src[N] = {}, tgt[N] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> src[i];
    src[i] %= MOD;
  }
  for (ll i = 0; i < n; ++i) {
    cin >> tgt[i];
    tgt[i] %= MOD;
  }
  sort(src, src + n);
  sort(tgt, tgt + n);

  for (ll i = 0; i < n; ++i) {
    if (src[i] != tgt[i]) {
      cout << "impossible\n";
      goto END;
    }
  }
  cout << "possible\n";

END:

  return 0;
}