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

cll H = 100, W = 100, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll h, w, mat[H + 2][W + 2] = {{}};
bool status[26] = {}, isGoal[H + 2][W + 2] = {{}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < h + 2 && l >= 0 && l < w + 2 && mat[i][l] != -2;
}

ll dfs() {
  qpll q;
  bool checked[H + 2][W + 2] = {{}};
  q.push({0, 0});
  checked[0][0] = true;

  ll result = 0;
  vpll reachable[26];
  for (ll i, l; !q.empty();) {
    tie(i, l) = q.front();
    q.pop();
    for (auto &d : directions) {
      ll ni = i + d[0], nl = l + d[1];
      if (!isValidCord(ni, nl)) {
        continue;
      } else if (mat[ni][nl] >= 26 && !status[mat[ni][nl] - 26]) {
        reachable[mat[ni][nl] - 26].emplace_back(ni, nl);
        continue;
      } else if (checked[ni][nl]) {
        continue;
      }

      if (mat[ni][nl] != -1 && mat[ni][nl] < 26) {
        if (!status[mat[ni][nl]]) {
          for (auto &p : reachable[mat[ni][nl]]) {
            if (checked[p.first][p.second]) {
              continue;
            }
            mat[p.first][p.second] = -1;
            checked[p.first][p.second] = true;
            q.push(p);
          }
          status[mat[ni][nl]] = true;
        }
      }

      if (isGoal[ni][nl]) {
        isGoal[ni][nl] = false, ++result;
      }
      checked[ni][nl] = true;
      q.push({ni, nl});
    }
  }

  return result;
}

ll solve() {
  cin >> h >> w;
  memset(status, 0, sizeof(status));
  memset(mat, -1, sizeof(mat));
  memset(isGoal, 0, sizeof(isGoal));
  for (ll i = 1; i <= h; ++i) {
    string str;
    cin >> str;
    for (ll l = 1; l <= w; ++l) {
      char c = str[l - 1];
      switch (c) {
      case '*':
        mat[i][l] = -2;
        break;
      case '.':
        break;
      case '$':
        isGoal[i][l] = true;
        break;
      default:
        if (c >= 'A' && c <= 'Z') {
          mat[i][l] = c - 'A' + 26;
        } else if (c >= 'a' && c <= 'z') {
          mat[i][l] = c - 'a';
        }
      }
    }
  }

  string str;
  cin >> str;
  if (str[0] != '0') {
    for (auto &c : str) {
      status[c - 'a'] = true;
    }
  }

  return dfs();
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