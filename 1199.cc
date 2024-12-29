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

cll N = 1000;
ll n, mat[N][N] = {{}}, visited[N] = {};

bool dfs(ll node) {
  for (ll av = 0; av < n; ++av) {
    if (!mat[node][av]) {
      continue;
    }

    if (visited[node] == n && visited[av] == 1) {
      goto SUCCESS;
    } else if (!visited[av]) {
      visited[av] = visited[node] + 1;
      if (dfs(av)) {
        goto SUCCESS;
      }
      visited[av] = 0;
    }
  }

  return false;
SUCCESS:
  cout << node << "\n";
  return true;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR2(i, l, n, n) { cin >> mat[i][l]; }

  visited[0] = 1;
  if (!dfs(0)) {
    cout << -1 << "\n";
  };

  return 0;
}