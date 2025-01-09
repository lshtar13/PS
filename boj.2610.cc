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

cll N = 100, INF = 1234;
ll n, m, k = 0;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  vector<bool> visited(n, false);
  vvll mat(n, vll(n, INF));
  vll maxDeliver(n, 0);
  for (ll a, b, i = 0; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    mat[a][b] = mat[b][a] = 1;
  }

  for (ll i = 0; i < n; ++i) {
    mat[i][i] = 0;
  }

  for (ll mid = 0; mid < n; ++mid) {
    FOR2(i, l, n, n) { mat[i][l] = min(mat[i][l], mat[i][mid] + mat[mid][l]); }
  }

  set<ll> result;
  for (ll st = 0; st < n; ++st) {
    if (visited[st]) {
      continue;
    }

    qll q;
    q.push(st);
    vll idxs = {st};
    visited[st] = true;
    while (!q.empty()) {
      ll node = q.front();
      q.pop();

      for (ll idx = 0; idx < n; ++idx) {
        if (node == idx || mat[node][idx] >= INF) {
          continue;
        }

        maxDeliver[node] = max(maxDeliver[node], mat[node][idx]);
        if (visited[idx]) {
          continue;
        }

        q.push(idx);
        visited[idx] = true;
        idxs.emplace_back(idx);
      }
    }

    ll maxIdx = st;
    for (auto idx : idxs) {
      if (maxDeliver[idx] < maxDeliver[maxIdx]) {
        maxIdx = idx;
      }
    }

    result.insert(maxIdx);
  }
  cout << result.size() << "\n";
  for (auto idx : result) {
    cout << idx + 1 << "\n";
  }

  return 0;
}