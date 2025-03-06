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

cll N = 16, G = 800, R = 26;
ll n, guilty[N], r[N][N] = {{}}, mafia;

ll find(ll remains, ll visited) {
  if (remains < 2) {
    return 0;
  }

  if (remains % 2) {
    ll toKill = -1, maxG = 0;
    for (ll c = 0; c < n; ++c) {
      if (visited & (1 << c)) {
        continue;
      } else if (maxG < guilty[c]) {
        maxG = guilty[c], toKill = c;
      }
    }

    if (toKill == mafia) {
      return 0;
    }

    visited |= (1 << toKill);

    return find(remains - 1, visited);
  } else {
    ll toKill = -1, maxNight = 0;
    for (ll c = 0; c < n; ++c) {
      if (visited & (1 << c)) {
        continue;
      } else if (c == mafia) {
        continue;
      } else {
        for (ll i = 0; i < n; ++i) {
          guilty[i] += r[c][i];
        }

        ll nnight = find(remains - 1, visited | (1 << c));

        for (ll i = 0; i < n; ++i) {
          guilty[i] -= r[c][i];
        }

        if (maxNight < nnight) {
          maxNight = nnight, toKill = c;
        }
      }
    }

    return maxNight + 1;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> guilty[i];
  }

  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> r[i][l];
    }
  }

  cin >> mafia;

  cout << find(n, 0) << "\n";

  return 0;
}