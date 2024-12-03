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
cll N = 10, INF = 10000;
ll n, popluation[N] = {};
vll edges[N];

ll find(const ll status) {
  ll result = INF, pops[2] = {}, nums[2] = {};
  bool visited[N] = {};
  qll q[2];

  for (ll node = 0; node < n; ++node) {
    bool statusNode = status & (1 << node);
    pops[statusNode] += popluation[node];
    if (++nums[statusNode] == 1) {
      q[statusNode].push(node);
      visited[node] = true;
    }
  }

  ll _nums[2] = {1, 1};
  for (ll i = 0; i < 2; ++i) {
    while (!q[i].empty()) {
      ll node = q[i].front();
      q[i].pop();

      for (auto &av : edges[node]) {
        bool statusAv = status & (1 << av);
        if (visited[av] || statusAv != i) {
          continue;
        }

        ++_nums[i];
        visited[av] = true;
        q[i].push(av);
      }
    }
  }

  if (_nums[0] != nums[0] || _nums[1] != nums[1]) {
    goto END;
  }

  result = abs(pops[0] - pops[1]);

END:
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll node = 0; node < n; ++node) {
    cin >> popluation[node];
  }

  for (ll nNbor, node = 0; node < n; ++node) {
    cin >> nNbor;
    for (ll nbor, i = 0; i < nNbor; ++i) {
      cin >> nbor;
      edges[node].emplace_back(nbor - 1);
    }
  }

  ll result = INF;
  for (ll status = 1; status < (1 << n) - 1; ++status) {
    result = min(result, find(status));
  }

  cout << (result == INF ? -1 : result) << "\n";

  return 0;
}