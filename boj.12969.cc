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

cll N = 30, K = N * (N - 1) / 2;
ll n, k;
char dp[N + 1][N][N][N][K + 1] = {{{{{{}}}}}};

string track(ll idx, ll a, ll b, ll c, ll s) {
  char cur = dp[idx][a][b][c][s];
  if (idx == n) {
    return "\n";
  }

  if (cur == 'A') {
    return "A" + track(idx + 1, a - 1, b, c, s - b - c);
  } else if (cur == 'B') {
    return "B" + track(idx + 1, a, b - 1, c, s - c);
  } else {
    return "C" + track(idx + 1, a, b, c - 1, s);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  dp[n][0][0][0][0] = '\n';
  for (ll i = n - 1, sum; i >= 0; --i) {
    sum = n - 1 - i;
    for (ll a = sum; a >= 0; --a) {
      for (ll b = sum - a; b >= 0; --b) {
        for (ll c = sum - a - b; c >= 0; --c) {
          for (ll s = 0; s <= k; ++s) {
            if (!dp[i + 1][a][b][c][s]) {
              continue;
            }
            // cout << a << "/" << b << "/" << c << "\n";

            dp[i][a + 1][b][c][s + b + c] = 'A';
            dp[i][a][b + 1][c][s + c] = 'B';
            dp[i][a][b][c + 1][s] = 'C';
          }
        }
      }
    }
  }

  for (ll a = n; a >= 0; --a) {
    for (ll b = n - a; b >= 0; --b) {
      for (ll c = n - a - b; c >= 0; --c) {
        if (dp[0][a][b][c][k]) {
          cout << track(0, a, b, c, k);
          goto END;
        }
      }
    }
  }

  cout << "-1\n";
END:

  return 0;
}