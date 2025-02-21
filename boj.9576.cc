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

cll N = 1e3, M = 1e3;
ll n, m;

bool dfs(ll book, bool visited[], ll appls[][2], ll matched[]) {
  if (visited[book]) {
    return false;
  }

  visited[book] = true;
  ll owner = matched[book];
  if (!owner) {
    return true;
  }

  for (ll nbook = book + 1; nbook <= appls[owner][1]; ++nbook) {
    if (dfs(nbook, visited, appls, matched)) {
      matched[nbook] = owner;
      return true;
    }
  }

  return false;
}

ll avail(ll idx, ll appls[][2], ll matched[]) {
  bool visited[N] = {};
  for (ll book = appls[idx][0]; book <= appls[idx][1]; ++book) {
    if (dfs(book, visited, appls, matched)) {
      matched[book] = idx;
      return 1;
    }
  }

  return 0;
}

ll solve() {
  ll appls[M + 1][2] = {{}}, matched[N] = {};

  cin >> n >> m;
  for (ll i = 1; i <= m; ++i) {
    cin >> appls[i][0] >> appls[i][1];
    --appls[i][0], --appls[i][1];
  }

  ll result = 0;
  for (ll i = 1; i <= m; ++i) {
    result += avail(i, appls, matched);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}