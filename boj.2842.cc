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
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

cll N = 50, Height = 1e6,
    directions[8][2] = {{0, 1},  {0, -1}, {1, 0},  {-1, 0},
                        {1, -1}, {1, 1},  {-1, 1}, {-1, -1}};
ll n, heights[N][N] = {}, ntgt = 0;
bool isTgt[N][N] = {{}}, checked[N][N] = {{}};
pll src;

inline bool isValid(ll i, ll l) { return i >= 0 && i < n && l >= 0 && l < n; }

bool isPossible(ll low, ll high) {
  ll nget = 0;
  memset(checked, 0, sizeof(checked));
  checked[src.first][src.second] = true;
  qpll q;
  q.push(src);
  while (!q.empty()) {
    ll i = q.front().first, l = q.front().second;
    q.pop();

    for (auto &d : directions) {
      ll ni = i + d[0], nl = l + d[1];
      if (isValid(ni, nl) || checked[ni][nl]) {
        continue;
      } else if (heights[ni][nl] < low || heights[ni][nl] > high) {
        continue;
      }

      if (isTgt[ni][nl]) {
        ++nget;
      }

      checked[ni][nl] = true;
      q.push({ni, nl});
    }
  }

  return nget == ntgt;
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
        src = {i, l};
      } else if (c == 'K') {
        isTgt[i][l] = true;
        ++ntgt;
      }
    }
  }
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> heights[i][l];
    }
  }

  ll result = Height;
  for (ll low = 1; low <= heights[src.first][src.second]; ++low) {
    ll st = low, en = Height, high = -1;
    while (st <= en) {
      ll mid = (st + en) / 2;
      if (isPossible(low, mid)) {
        high = mid, en = mid - 1;
      } else {
        st = mid + 1;
      }
    }

    if (high != -1) {
      result = min(result, high - low);
    }
  }

  cout << result << "\n";

  return 0;
}