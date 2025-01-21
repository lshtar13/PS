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

cll N = 500;
ll n, dp[N][N] = {{}};
string dna;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> dna;
  n = dna.length();
  for (ll idx = 0; idx < n; ++idx) {
    dp[idx][idx] = 0;
  }

  for (ll len = 2; len <= n; ++len) {
    for (ll st = 0; st + len - 1 < n; ++st) {
      ll en = st + len - 1;
      for (ll mid = st; mid < en; ++mid) {
        dp[st][en] = max(dp[st][en], dp[st][mid] + dp[mid + 1][en]);
      }

      if (dna[st] == 'a' && dna[en] == 't') {
        dp[st][en] = max(dp[st][en], dp[st + 1][en - 1] + 2);
      }
      if (dna[st] == 'g' && dna[en] == 'c') {
        dp[st][en] = max(dp[st][en], dp[st + 1][en - 1] + 2);
      }
    }
  }

  cout << dp[0][n - 1] << "\n";

  return 0;
}