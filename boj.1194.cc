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

typedef tuple<ll, ll, ll> info_t;

cll N = 50, M = 50, STATUS = 1 << 6, INVALID = -(1 << 7),
    directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, mat[N][M] = {{}}, minTime[N][M][STATUS] = {{{}}};
pll src;
vpll dst;

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < m && mat[i][l] != INVALID;
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
      if (c == '.') {
        mat[i][l] = 0;
      } else if (c == '#') {
        mat[i][l] = INVALID;
      } else if (c == '0') {
        src = {i, l};
      } else if (c == '1') {
        dst.emplace_back(i, l);
      } else if (c < 'a') {
        mat[i][l] = -(1 << (c - 'a'));
      } else {
        mat[i][l] = (1 << (c - 'A'));
      }
    }
  }

  memset(minTime, -1, sizeof(minTime));

  queue<info_t> q;
  q.push({src.first, src.second, 0});
  minTime[src.first][src.second][0] = 0;

  for (ll i, l, status; !q.empty();) {
    tie(i, l, status) = q.front();
    q.pop();
    for (auto &d : directions) {
      ll ni = i + d[0], nl = l + d[1], nstatus = status;
      if (!isValidCord(ni, nl)) {
        continue;
      } else if (mat[ni][nl] < 0 && !((-mat[ni][nl]) & status)) {
        continue;
      }

      if (mat[ni][nl] > 0) {
        nstatus |= mat[ni][nl];
      }

      if (minTime[ni][nl][nstatus] != -1) {
        continue;
      }

      minTime[ni][nl][nstatus] = minTime[i][l][status] + 1;
      q.push({ni, nl, nstatus});
    }
  }

  ll result = 1e9;
  for (auto &p : dst) {
    for (ll status = 0; status < STATUS; ++status) {
      if (minTime[p.first][p.second][status] != -1) {
        result = min(result, minTime[p.first][p.second][status]);
      }
    }
  }

  if (result == 1e9) {
    cout << "-1\n";
  } else {
    cout << result << "\n";
  }

  return 0;
}