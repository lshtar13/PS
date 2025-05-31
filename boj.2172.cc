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

cll N = 20, Len = 20, directions[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                                          {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
ll n, length, nums[N * N] = {{}}, dp[N * N][N * N][Len + 1] = {{{}}};

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> length;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> nums[i * n + l];
    }
  }

  for (ll src = 0; src < n * n; ++src) {
    dp[src][src][1] = 1;
  }

  for (ll src = 0; src < n * n; ++src) {
    ll si = src / n, sl = src % n;
    for (auto &d : directions) {
      ll di = si + d[0], dl = sl + d[1], dst = di * n + dl;
      if (!isValidCord(di, dl) || nums[src] != nums[dst]) {
        continue;
      }

      dp[src][dst][2] = 1;
    }
  }

  for (ll len = 3; len <= length; ++len) {
    for (ll src = 0; src < n * n; ++src) {
      for (ll dst = 0; dst < n * n; ++dst) {
        ll &value = dp[src][dst][len] = 0;
        if (nums[src] != nums[dst]) {
          continue;
        }

        ll si = src / n, sl = src % n, di = dst / n, dl = dst % n;
        for (auto &d : directions) {
          ll nsi = si + d[0], nsl = sl + d[1], nsrc = nsi * n + nsl;
          if (!isValidCord(nsi, nsl)) {
            continue;
          }

          for (auto &d : directions) {
            ll ndi = di + d[0], ndl = dl + d[1], ndst = ndi * n + ndl;
            if (!isValidCord(ndi, ndl)) {
              continue;
            }

            value += dp[nsrc][ndst][len - 2];
          }
        }
      }
    }
  }

  ll result = 0;
  for (ll src = 0; src < n * n; ++src) {
    for (ll dst = 0; dst < n * n; ++dst) {
      result += dp[src][dst][length];
    }
  }

  cout << result << "\n";

  return 0;
}