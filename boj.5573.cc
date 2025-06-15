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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll H = 1000, W = 1000, N = 1e7;
ll h, w, n, dp[H][W][2];
bool mat[H][W] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> h >> w >> n;
  FOR(i, h) FOR(l, w) { cin >> mat[i][l]; }

  return 0;
}