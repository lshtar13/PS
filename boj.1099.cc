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

cll NWORD = 50, NALPHA = 'z' - 'a' + 1, INF = NWORD + 1;
char tgt[NWORD + 1] = {};
string words[NWORD];
ll nword, len, wordStatus[NWORD][NALPHA] = {{}}, sum[NWORD + 1][NALPHA] = {{}};
vll dp(NWORD + 1, INF);

ll cost(ll idx, ll st, ll en) {
  ll result = INF, cost = en - st;
  for (ll a = 0; a < NALPHA; ++a) {
    if (sum[en][a] - sum[st][a] != wordStatus[idx][a]) {
      goto END;
    }
  }

  for (ll c = st; c < en; ++c) {
    cost -= (words[idx][c - st] == tgt[c]);
  }
  result = min(result, cost);

END:
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> tgt >> nword;
  for (ll i = 0; i < nword; ++i) {
    cin >> words[i];
    for (auto &c : words[i]) {
      ++wordStatus[i][c - 'a'];
    }
  }

  ll len = strlen(tgt);
  for (ll idx, i = 0; i < len; ++i) {
    idx = tgt[i] - 'a';
    for (ll c = 0; c < NALPHA; ++c) {
      sum[i + 1][c] = sum[i][c];
    }
    ++sum[i + 1][idx];
  }

  dp[0] = 0;
  for (ll i = 1; i <= len; ++i) {
    for (ll w = 0; w < nword; ++w) {
      ll len = words[w].length();
      if (i < len) {
        continue;
      }

      dp[i] = min(dp[i], cost(w, i - len, i) + dp[i - len]);
    }
  }

  cout << (dp[len] >= INF ? -1 : dp[len]) << "\n";

  return 0;
}