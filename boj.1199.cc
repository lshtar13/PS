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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 1000;
ll n, nedges = 0, mat[N][N] = {{}};
vll edges[N];

bool dfs(ll node) {
  if (nedges == 0) {
    if (!node) {
      cout << node + 1 << " ";
      return true;
    } else {
      return false;
    }
  }

  for (auto &av : edges[node]) {
    if (mat[node][av] <= 0) {
      continue;
    }

    --mat[node][av], --mat[av][node], --nedges;
    if (dfs(av)) {
      cout << node + 1 << " ";
      return true;
    }
    ++mat[node][av], ++mat[av][node], ++nedges;
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // dfs?
  cin >> n;
  FOR(i, 0, n) FOR(l, 0, n) {
    cin >> mat[i][l];
    nedges += mat[i][l];
    edges[i].emplace_back(l);
  }
  nedges /= 2;

  dfs(0);

  return 0;
}