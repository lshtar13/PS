#include <bits/stdc++.h>
#include <climits>
#include <deque>

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

cll N = 50, HEIGHT = 1e6,
    directions[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
ll n, nTgt = 0, heights[N][N] = {{}};
pll home;
bool isTgt[N][N] = {{}};

inline bool isValid(ll i, ll l) { return i < n && i >= 0 && l < n && l >= 0; }

bool avail(ll minH, ll maxH) {
  bool visited[N][N] = {{}};
  qpll q;
  q.push(home);
  visited[home.first][home.second] = true;

  ll i, l, _i, _l, cnt = 0;
  while (!q.empty()) {
    tie(i, l) = q.front();
    q.pop();

    for (auto &d : directions) {
      _i = i + d[0], _l = l + d[1];
      if (!isValid(_i, _l) || visited[_i][_l]) {
        continue;
      } else if (heights[_i][_l] > maxH || heights[_i][_l] < minH) {
        continue;
      }

      visited[_i][_l] = true;
      q.push({_i, _l});
    }
  }

  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      if (isTgt[i][l] && visited[i][l]) {
        ++cnt;
      }
    }
  }

  return cnt == nTgt;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < n; ++l) {
      char c;
      cin >> c;
      if (c == 'P') {
        home = {i, l};
      } else if (c == 'K') {
        isTgt[i][l] = true;
        ++nTgt;
      }
    }
  }

  vll candidates;
  FOR2(i, l, n, n) {
    cin >> heights[i][l];
    candidates.emplace_back(heights[i][l]);
  }
  sort(candidates.begin(), candidates.end());

  ll left = 0, right = 0, result = HEIGHT;
  while (left <= right && right < candidates.size()) {
    while (avail(candidates[left], candidates[right])) {
      result = min(result, candidates[right] - candidates[left]);
      ++left;
    }
    ++right;
  }

END:
  cout << result << '\n';

  return 0;
}