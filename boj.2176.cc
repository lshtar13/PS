#include <bits/stdc++.h>
#include <queue>

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

cll S = 0, T = 1, N = 1000, M = 1e5, C = 1e4, INF = M * C + 1;
ll n, m, lengths[N] = {}, dp[N] = {};
vpll edges[N];

ll findKind(ll node) {
  if (dp[node] != -1) {
    return dp[node];
  }

  ll av, w;
  dp[node] = 0;
  for (auto &p : edges[node]) {
    tie(av, w) = p;
    if (lengths[av] + w == lengths[node]) {
      dp[node] += findKind(av);
    }
  }

  return dp[node];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }

  memset(lengths, 0x3f3f3f3f, sizeof(lengths));
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  pq.push({lengths[T] = 0, T});
  while (!pq.empty()) {
    ll length, node;
    tie(length, node) = pq.top();
    pq.pop();

    if (lengths[node] < length) {
      continue;
    }

    ll av, w, nlength;
    for (auto &p : edges[node]) {
      tie(av, w) = p;

      nlength = length + w;
      if (lengths[av] > nlength) {
        lengths[av] = nlength;
        pq.push({nlength, av});
      }
    }
  }

  for (ll node = 0; node < n; ++node) {
    pq.push({lengths[node], node});
  }

  ll node, length;
  dp[T] = 1;
  while (!pq.empty()) {
    tie(length, node) = pq.top();
    pq.pop();
    if (node == T) {
      continue;
    }

    ll av, w;
    dp[node] = 0;
    for (auto &p : edges[node]) {
      tie(av, w) = p;

      if (lengths[av] < length) {
        dp[node] += dp[av];
      }
    }
  }
  cout << dp[S] << "\n";

  return 0;
}