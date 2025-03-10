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

cll N = 50, M = 50, INF = N * M + 1,
    directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, dp[N][M] = {{}};
bool visited[N][M] = {{}};
char mat[N][M] = {{}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < m;
}

ll findMax(ll i, ll l) {
  if (visited[i][l]) {
    return INF;
  } else if (dp[i][l] != -1) {
    return dp[i][l];
  }

  //   cout << i << "/" << l << " " << ll(mat[i][l]) << "\n";

  ll result = 0, next;
  visited[i][l] = true;
  for (auto &d : directions) {
    bool isOk = true;
    ll ni = i, nl = l;
    for (ll step = 0; step < mat[i][l]; ++step) {
      ni += d[0], nl += d[1];
      if (!isValidCord(ni, nl)) {
        isOk = false;
        break;
      }
    }

    if (!isOk || !mat[ni][nl]) {
      continue;
    }

    next = findMax(ni, nl);
    result = max(result, next + 1);
  }

  visited[i][l] = false;

  return dp[i][l] = result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < m; ++l) {
      cin >> mat[i][l];
      if (mat[i][l] == 'H') {
        mat[i][l] = 0;
      } else {
        mat[i][l] -= '0';
      }
    }
  }

  memset(dp, -1, sizeof(dp));

  ll result = findMax(0, 0);
  result = result >= INF ? -1 : result + 1;
  cout << result << '\n';

  return 0;
}