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

cll N = 100, Inf = 1e9;
ll n, dp[N + 1][10][10][10] = {{{{}}}};
char cur[N + 3] = {}, goal[N + 3] = {};

ll check(ll idx, ll a, ll b, ll c) {
  if (idx == n) {
    return 0;
  }

  ll &value = dp[idx][a][b][c],
     togo[2] = {(goal[idx] - a + 10) % 10, (a - goal[idx] + 10) % 10};
  if (value != -1) {
    return value;
  }
  value = Inf;

  FOR(dir, 2)
  FOR(cb, togo[dir] + 1) FOR(cc, cb + 1) {
    ll click = (cc + 2) / 3 + (cb - cc + 2) / 3 + (togo[dir] - cb + 2) / 3,
       derv = !dir ? 1 : -1, nb = (b + derv * cb + 10) % 10,
       nc = (c + derv * cc + 10) % 10;

    value = min(value, click + check(idx + 1, nb, nc, cur[idx + 3]));
  }

  return value;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin.ignore();
  FOR(i, n) {
    cin >> cur[i];
    cur[i] -= '0';
  }
  cin.ignore();
  FOR(i, n) {
    cin >> goal[i];
    goal[i] -= '0';
  }
  memset(dp, -1, sizeof(dp));

  cout << check(0, cur[0], cur[1], cur[2]);

  return 0;
}