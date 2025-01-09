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

cll INF = 100;
ll mat[10][10] = {{}}, kind[6] = {0, 5, 5, 5, 5, 5};

inline bool isValid(ll i, ll l) { return i >= 0 && i < 10 && l >= 0 && l < 10; }

ll find(ll idx) {
  ll result = INF, i = idx / 10, l = idx % 10;
  if (idx >= 100) {
    return 0;
  } else if (!mat[i][l]) {
    return find(idx + 1);
  }

  for (ll d = 1; d <= 5;) {
    if (!kind[d]) {
      goto skip;
    }

    FOR2(di, dl, d, d) {
      if (!isValid(i + di, l + dl) || !mat[i + di][l + dl]) {
        goto skip;
      }
    }
    --kind[d];
    FOR2(di, dl, d, d) { mat[i + di][l + dl] = 0; }
    result = min(result, find(idx + d) + 1);
    FOR2(di, dl, d, d) { mat[i + di][l + dl] = 1; }
    ++kind[d];

  skip:
    ++d;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  FOR2(i, l, 10, 10) { cin >> mat[i][l]; }

  ll result = find(0);
  cout << (result >= INF ? -1 : result) << "\n";

  return 0;
}