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

cll N = 50, M = 50, G = 5, R = 5, INF = N * M + 2,
    directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, g, r;
bool mat[N][M] = {{}};
vpll avail;

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < m && mat[i][l];
}

vvpll getN(vpll::iterator st, vpll::iterator en, ll n) {
  ll size = en - st;
  if (!n) {
    return {{}};
  }

  vvpll results;
  for (auto it = en - 1; it - st >= n - 1; --it) {
    for (auto &v : getN(st, it, n - 1)) {
      v.push_back(*it);
      results.emplace_back(v);
    }
  }

  return results;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> g >> r;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0, value; l < m; ++l) {
      cin >> value;
      mat[i][l] = value != 0;
      if (value == 2) {
        avail.emplace_back(i, l);
      }
    }
  }

  ll result = 0;
  for (auto &total : getN(avail.begin(), avail.end(), g + r)) {
    for (auto &greens : getN(total.begin(), total.end(), g)) {
      ll nflower = 0, checked[N][M] = {{}};
      bool flourished[N][M] = {{}};

      qpll q;
      set<pll> s;
      for (auto &green : greens) {
        s.insert(green);
        q.push(green);
        checked[green.first][green.second] = 1;
      }

      for (auto &red : total) {
        if (s.find(red) == s.end()) {
          q.push(red);
          checked[red.first][red.second] = -1;
        }
      }

      for (ll i, l, nvalue; !q.empty();) {
        tie(i, l) = q.front();
        q.pop();

        if (checked[i][l] == INF) {
          continue;
        }

        if (checked[i][l] > 0) {
          nvalue = checked[i][l] + 1;
        } else {
          nvalue = checked[i][l] - 1;
        }

        for (auto &d : directions) {
          ll ni = i + d[0], nl = l + d[1];
          if (!isValidCord(ni, nl)) {
            continue;
          }

          if (checked[ni][nl]) {
            if (checked[ni][nl] + nvalue == 0) {
              ++nflower, checked[ni][nl] = INF;
            }
            continue;
          }

          checked[ni][nl] = nvalue;
          q.push({ni, nl});
        }
      }

      result = max(result, nflower);
    }
  }

  cout << result << "\n";

  return 0;
}