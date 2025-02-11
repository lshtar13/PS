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

cll N = 2e3, M = 2e6;
ll n, m, segs[N * 10] = {};
pll edges[M];

ll increase(ll node, ll st, ll en, ll idx) {
  if (st > idx || en < idx) {
    return segs[node];
  } else if (st == en) {
    return ++segs[node];
  }

  ll mid = (st + en) / 2;
  return segs[node] = increase(node * 2, st, mid, idx) +
                      increase(node * 2 + 1, mid + 1, en, idx);
}

ll query(ll node, ll st, ll en, ll idx) {
  if (en < idx) {
    return 0;
  } else if (st >= idx) {
    return segs[node];
  }

  ll mid = (st + en) / 2;
  return query(node * 2, st, mid, idx) + query(node * 2 + 1, mid + 1, en, idx);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < m; ++i) {
    cin >> edges[i].first >> edges[i].second;
  }
  sort(edges, edges + m);

  ll result = 0;
  for (ll i = 0, a, b; i < m; ++i) {
    tie(a, b) = edges[i];
    result += query(1, 1, n, b);
    increase(1, 1, n, b);
  }

  cout << result << '\n';

  return 0;
}