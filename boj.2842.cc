#include <bits/stdc++.h>
#include <string>

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

cll N = 50, Height = 1e6,
    directions[8][2] = {{0, 1},  {0, -1}, {1, 0},  {-1, 0},
                        {1, -1}, {1, 1},  {-1, 1}, {-1, -1}};
ll n, mat[N][N] = {}, ntgt = 0, minHeight = Height, maxHeight = 0;
bool isTgt[N][N] = {{}}, checked[N][N] = {{}};
pll src;
vll heights;
set<ll> s;

inline bool isValid(ll i, ll l) { return i >= 0 && i < n && l >= 0 && l < n; }

bool isPossible(ll low, ll high) {
  if (mat[src.first][src.second] < low || mat[src.first][src.second] > high) {
    return false;
  }

  ll nvisited = 0;
  bool checked[N][N] = {{}};
  checked[src.first][src.second] = true;
  qpll q;
  q.push(src);
  while (!q.empty()) {
    ll i = q.front().first, l = q.front().second;
    q.pop();

    for (auto &d : directions) {
      ll ni = i + d[0], nl = l + d[1];
      if (!isValid(ni, nl) || checked[ni][nl]) {
        continue;
      } else if (mat[ni][nl] < low || mat[ni][nl] > high) {
        continue;
      }

      if (isTgt[ni][nl]) {
        ++nvisited;
      }

      checked[ni][nl] = true;
      q.push({ni, nl});
    }
  }

  return nvisited == ntgt;
}

ll findLow(ll high) {
  ll st = minHeight, en = high, ans = -1;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if (isPossible(mid, high)) {
      ans = mid, st = mid + 1;
    } else {
      en = mid - 1;
    }
  }

  return ans;
}

ll findHigh(ll low) {
  ll st = low, en = maxHeight, ans = -1;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if (isPossible(low, mid)) {
      ans = mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  return ans;
}

int main(void) {
  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < n; ++l) {
      char c;
      cin >> c;
      if (c == 'P') {
        src = {i, l};
      } else if (c == 'K') {
        isTgt[i][l] = true, ++ntgt;
      }
    }
  }

  FOR(i, n) FOR(l, n) {
    cin >> mat[i][l];
    minHeight = min(minHeight, mat[i][l]),
    maxHeight = max(maxHeight, mat[i][l]);
    s.insert(mat[i][l]);
  }

  for (auto &height : s) {
    heights.emplace_back(height);
  }

  ll low = 0, high = 0, result = Height;
  while (high < heights.size()) {
    if (isPossible(heights[low], heights[high])) {
      result = min(result, heights[high] - heights[low]), ++low;
    } else {
      ++high;
    }

    if (low > high) {
      ++high;
    }
  }

  cout << result << "\n";

  return 0;
}