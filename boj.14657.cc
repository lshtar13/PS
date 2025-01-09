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

cll N = 5e4, T = 1e5, INF = 1e10;
ll n, t;
vvpll edges(N + 1);
map<ll, pll> m;

pll find(ll prev, ll node) {
  ll idx = prev * (N + 1) + node;
  if (m.find(idx) != m.end()) {
    return m[idx];
  }

  ll nproblem = 0, weights = INF;
  for (auto &p : edges[node]) {
    if (prev == p.first) {
      continue;
    }

    pll result = find(node, p.first);
    if (result.first > nproblem) {
      nproblem = result.first, weights = result.second + p.second;
    } else if (result.first == nproblem) {
      weights = min(weights, result.second + p.second);
    }
  }

  weights = weights == INF ? 0 : weights;
  return m[idx] = make_pair(nproblem + 1, weights);
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

  cin >> n >> t;
  for (ll a, b, c, i = 0; i < n - 1; ++i) {
    cin >> a >> b >> c;
    edges[a].emplace_back(make_pair(b, c));
    edges[b].emplace_back(make_pair(a, c));
  }

  pll result(0, INF);
  for (ll i = 1; i <= n; ++i) {
    // cout << i << "\n";
    pll p = find(0, i);
    if (p.first > result.first) {
      result = p;
    } else if (p.first == result.first && p.second < result.second) {
      result = p;
    }
  }

  cout << result.second / t + bool(result.second % t) << "\n";

  return 0;
}