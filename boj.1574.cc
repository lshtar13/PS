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

cll R = 300, C = 300, N = 600;
ll r, c, n, owner[R + C] = {{}};
bool isEmpty[R][C] = {{}};

bool check(ll idx) {
  
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c >> n;
  FOR(i, n) {
    ll a, b;
    cin >> a >> b;
    isEmpty[--a][--b] = true;
  }

  ll result = 0;
  FOR(row, r) { ll idx = row + c; }
  FOR(column, c) { ll idx = column; }

  return 0;
}