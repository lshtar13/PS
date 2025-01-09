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

cll N = 10000, NUM = 10, INF = N * NUM;
ll n, state[N] = {}, goal[N] = {}, dp[N][NUM] = {{}};

ll find(ll idx, ll num) {
  ll next, toGo, result;
  if (idx == n) {
    return 0;
  } else if (dp[idx][num] != -1) {
    goto END;
  }
  next = (state[idx + 1] + num - state[idx] + NUM) % NUM;

  // left
  toGo = (goal[idx] - num + NUM) % NUM;
  result = find(idx + 1, (next + toGo) % NUM) + toGo;

  // right
  toGo = (num - goal[idx] + NUM) % NUM;
  result = min(result, find(idx + 1, next) + toGo);

  dp[idx][num] = result;

END:
  return dp[idx][num];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin.ignore();
  FOR1(i, n) {
    char c;
    cin >> c;
    state[i] = c - '0';
  }
  cin.ignore();
  FOR1(i, n) {
    char c;
    cin >> c;
    goal[i] = c - '0';
  }

  memset(dp, -1, sizeof(dp));

  cout << find(0, state[0]) << "\n";

  return 0;
}