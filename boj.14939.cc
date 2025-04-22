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

cll N = 10, INF = N * N + 1;
ll bulbs[N + 1] = {};

ll find(ll idx, ll cur, ll prv) {
  ll next = bulbs[idx + 1], nchanged = 0;
  for (ll i = 0; i < N; ++i) {
    if (prv & (1 << i)) {
      ++nchanged, cur ^= (1 << i), next ^= (1 << i);
      if (i > 0) {
        cur ^= (1 << (i - 1));
      }
      if (i < N - 1) {
        cur ^= (1 << (i + 1));
      }
    }
  }

  if (idx == N - 1) {
    if (cur == 0) {
      return nchanged;
    } else {
      return INF;
    }
  } else {
    return nchanged + find(idx + 1, next, cur);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (ll i = 0; i < N; ++i) {
    for (ll l = 0; l < N; ++l) {
      char c;
      cin >> c;
      if (c == 'O') {
        bulbs[i] |= (1 << l);
      }
    }
    cin.ignore();
  }

  ll result = INF;
  for (ll choice = 0, cur, next, nchanged; choice < (1 << N); ++choice) {
    cur = bulbs[0], next = bulbs[1], nchanged = 0;
    for (ll i = 0; i < N; ++i) {
      if (choice & (1 << i)) {
        ++nchanged, next ^= (1 << i);
        cur ^= (1 << i);
        if (i > 0) {
          cur ^= (1 << (i - 1));
        }
        if (i < N - 1) {
          cur ^= (1 << (i + 1));
        }
      }
    }

    result = min(result, nchanged + find(1, next, cur));
  }

  cout << (result == INF ? -1 : result) << "\n";

  return 0;
}