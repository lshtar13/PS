#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

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

cll N = 100, M = 100;
ll n, m, src, sink, cap[N + M + 2][N + M + 2] = {{}},
                                           flow[N + M + 2][N + M + 2] = {{}},
                                           parents[N + M + 2] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  src = 0, sink = n + m + 1;
  for (ll cust = 1; cust <= n; ++cust) {
    cin >> cap[src][cust];
  }
  for (ll store = n + 1; store <= n + m; ++store) {
    cin >> cap[store][sink];
  }

  for (ll store = n + 1; store <= n + m; ++store) {
    for (ll cust = 1; cust <= n; ++cust) {
      cin >> cap[cust][store];
    }
  }

  ll result = 0;
  while (true) {
    memset(parents, -1, sizeof(parents));

    qll q;
    q.push(src);
    parents[src] = src;

    while (!q.empty()) {
      ll dpt = q.front();
      q.pop();

      for (ll dst = 0; dst <= sink; ++dst) {
        if (parents[dst] != -1) {
          continue;
        } else if (cap[dpt][dst] - flow[dpt][dst] > 0) {
          q.push(dst);
          parents[dst] = dpt;
        }
      }
    }

    if (parents[sink] == -1) {
      break;
    }

    ll amnt = LLONG_MAX;
    for (ll p = sink; p != src; p = parents[p]) {
      amnt = min(amnt, cap[parents[p]][p] - flow[parents[p]][p]);
    }

    for (ll p = sink; p != src; p = parents[p]) {
      flow[parents[p]][p] += amnt;
      flow[p][parents[p]] -= amnt;
    }

    result += amnt;
  }

  cout << result << "\n";

  return 0;
}