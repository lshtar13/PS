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

cll N = 2e5, M = 5e5;
ll n, m, num = 0, idx = 0, parents[N + 1] = {}, cycles[N + 1] = {};
vll edges[N + 1];

ll findCycle(ll node) {
  static stack<ll> s;
  if (parents[node]) {
    return parents[node];
  }

  s.push(node);
  ll cidx = parents[node] = ++idx;
  for (auto &av : edges[node]) {
    if (!cycles[av]) {
      parents[node] = min(parents[node], findCycle(av));
    }
  }

  while (parents[node] == cidx && !s.empty()) {
    ll mem = s.top();
    s.pop();
    cycles[mem] = node;

    if (node == mem) {
      ++num;
      break;
    }
  }

  return parents[node];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0, v, w; i < m; ++i) {
    cin >> v >> w;
    edges[v].emplace_back(w);
  }

  // 싸이클
  for (ll node = 1; node <= n; ++node) {
    findCycle(node);
    if (num > 1) {
      cout << "No\n";
      goto END;
    }
  }
  cout << "Yes\n";
END:

  return 0;
}