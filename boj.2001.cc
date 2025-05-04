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

cll N = 100, M = 1000, K = 14, STATUS = 1 << K;
ll n, m, k, jems[N] = {};
bool checked[N][STATUS] = {};
vpll edges[N];

inline bool included(ll status, ll idx) { return (status & (1 << idx)); }
ll count(ll status) {
  ll result = 0;
  for (ll i = 0; i < K; ++i) {
    result += bool(status & (1 << i));
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(jems, -1, sizeof(jems));

  cin >> n >> m >> k;
  for (ll i = 0, island; i < k; ++i) {
    cin >> island;
    jems[--island] = i;
  }
  for (ll i = 0, a, b, c; i < m; ++i) {
    cin >> a >> b >> c;
    --a, --b;
    edges[a].emplace_back(b, c);
    edges[b].emplace_back(a, c);
  }

  // bfs
  qpll q;
  checked[0][0] = true;
  q.push({0, 0});
  for (ll idx, status, jdx; !q.empty();) {
    tie(idx, status) = q.front();
    q.pop();

    jdx = jems[idx];
    if (jdx != -1 && !included(status, jdx)) {
      ll nstatus = status | (1 << jdx), njem = count(status) + 1;
      checked[idx][nstatus] = true;
      q.push({idx, nstatus});
    }

    ll nstatus = status, njem = count(status);
    for (auto &p : edges[idx]) {
      ll nidx = p.first, limit = p.second;
      if (njem > limit || checked[nidx][nstatus]) {
        continue;
      }

      checked[nidx][nstatus] = true;
      q.push({nidx, nstatus});
    }
  }

  ll result = 0;
  for (ll status = 0; status < (1 << k); ++status) {
    if (checked[0][status]) {
      result = max(result, count(status));
    }
  }

  cout << result << "\n";

  return 0;
}