#include <bits/stdc++.h>
#include <climits>

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

cll N = 50, M = 50, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m, st, c;
vll dsts;
bool mat[N * M] = {};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < m;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < m; ++l) {
      char c;
      cin >> c;
      if (c == 'S') {
        st = i * m + l;
      } else if (c == 'C') {
        dsts.emplace_back(i * m + l);
      } else {
        mat[i * m + l] = (c == '#');
      }
    }
  }

  ll result = LLONG_MAX;
  result = min(result, find(st, dsts[0]) + find(dsts[0], dsts[1]));
  result = min(result, find(st, dsts[1]) + find(dsts[1], dsts[0]));

  cout << -1 << "\n";
END:

  return 0;
}