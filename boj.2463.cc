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

typedef tuple<ll, ll, ll> info_t;

cll N = 1e5, M = 1e5, MOD = 1e9;
ll n, m, parents[N] = {}, nMember[N] = {}, sum = 0, x, y, w;

ll findParent(ll node) {
  if (parents[node] == node) {
    return node;
  } else {
    parents[node] = findParent(parents[node]);
    nMember[node] = nMember[parents[node]];
    return parents[node];
  }
}

void merge(ll a, ll b) {
  a = findParent(a), b = findParent(b);
  nMember[a] += nMember[b];
  parents[b] = a;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    parents[i] = i, nMember[i] = 1;
  }

  priority_queue<info_t> pq;
  for (ll i = 0; i < m; ++i) {
    cin >> x >> y >> w;
    pq.push({w, --x, --y});
    sum += w;
  }

  ll result = 0;
  while (!pq.empty()) {
    tie(w, x, y) = pq.top();
    pq.pop();

    x = findParent(x), y = findParent(y);
    if (x != y) {
      result += sum * (nMember[x] * nMember[y]);
      result %= MOD;
      merge(x, y);
    }

    sum -= w;
  }

  cout << result << "\n";

  return 0;
}