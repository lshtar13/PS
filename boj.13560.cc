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

cll N = 1e4;
ll n, sum = 0, wins[N] = {}, loses[N] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> wins[i];
    sum += wins[i];
  }
  sort(wins, wins + n);

  if (sum != (n * (n - 1)) / 2) {
    cout << "-1\n";
    goto END;
  }

  for (ll i = 0, lose; i < n; ++i) {
    

    if (wins[i] || loses[i]) {
      cout << "-1\n";
      goto END;
    }
  }
  cout << "1\n";

END:

  return 0;
}