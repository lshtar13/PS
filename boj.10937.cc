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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 11, CLASS = 4, Node = N * N + 2, Snk = 1, Src = 0,
    directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}},
    prices[CLASS][CLASS] = {
        {100, 70, 40, 0}, {70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0}};
ll n, mat[N][N] = {{}}, caps[Node][Node] = {{}}, flows[Node][Node] = {{}},
      costs[Node][Node] = {{}}, dists[Node] = {}, prvs[Node] = {};
bool inQueue[Node] = {};

vll edges[Node];

inline bool isValidCord(ll i, ll l) {
  return i >= 0 && i < n && l >= 0 && l < n;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < n; ++l) {
      char c;
      cin >> c;

      if (c < 'F') {
        mat[i][l] = c - 'A';
      } else {
        mat[i][l] = 3;
      }
    }
  }

  for (ll node = 2; node < n * n + 2; ++node) {
    if (node % 2 == 0) {
      edges[Src].emplace_back(node);
      edges[node].emplace_back(Src);
      caps[Src][node] = 1;
      ll i = (node - 2) / n, l = (node - 2) % n;
      for (auto &d : directions) {
        ll ni = i + d[0], nl = l + d[1], nnode;
        if (!isValidCord(ni, nl)) {
          continue;
        }

        nnode = ni * n + nl + 2;
        caps[node][nnode] = 1,
        costs[node][nnode] = prices[mat[i][l]][mat[ni][nl]];
        costs[nnode][node] = -prices[mat[i][l]][mat[ni][nl]];
        edges[node].emplace_back(nnode);
        edges[nnode].emplace_back(node);
      }
    } else {
      caps[node][Snk] = 1;
      edges[Snk].emplace_back(node);
      edges[node].emplace_back(Snk);
    }
  }

  ll result = 0;
  while (true) {
    memset(dists, -1, sizeof(dists));
    memset(inQueue, 0, sizeof(inQueue));
    memset(prvs, -1, sizeof(prvs));

    qll q;
    q.push(Src);
    prvs[Src] = 0, dists[Src] = 0, inQueue[Src] = true;
    while (!q.empty()) {
      ll node = q.front();
      q.pop();
      inQueue[node] = false;
      for (auto &av : edges[node]) {
        if (caps[node][av] - flows[node][av] <= 0 ||
            dists[av] > dists[node] + costs[node][av]) {
          continue;
        }

        dists[av] = dists[node] + costs[node][av], prvs[av] = node;
        if (!inQueue[av]) {
          q.push(av);
          inQueue[av] = true;
        }
      }
    }

    if (prvs[Snk] == -1) {
      break;
    }

    for (ll cur = Snk, prv = prvs[cur]; cur != Src;
         cur = prv, prv = prvs[cur]) {
      ++flows[prv][cur], --flows[cur][prv];
    }
    result += dists[Snk];
  }

  cout << result << "\n";

  return 0;
}

// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;
// typedef pair<ll, ll> pll;
// typedef pair<ull, ull> pull;
// typedef const ll cll;
// typedef queue<ll> qll;
// typedef queue<pll> qpll;
// typedef priority_queue<ll> pqll;
// typedef priority_queue<pll> pqpll;
// typedef vector<ll> vll;
// typedef vector<pll> vpll;
// typedef vector<vll> vvll;
// typedef vector<vpll> vvpll;
// #define FOR(a, A) for (ll a = 0; a < A; ++a)

// cll Class = 4, N = 11,
//     prices[Class][Class] = {
//         {100, 70, 40, 0}, {70, 50, 30, 0}, {40, 30, 20, 0}, {0, 0, 0, 0}};
// ll n, mat[N][N] = {{}}, dp[N + 1][1 << N] = {{}};
// bool checked[N][N] = {{}};

// inline bool isValidCord(ll i, ll l) {
//   return i >= 0 && i < n && l >= 0 && l < n;
// }

// ll check(ll, ll);

// ll dfs(ll i, ll l, ll status, ll nstatus) {
//   if (l >= n) {
//     return check(i + 1, nstatus);
//   } else if (status & (1 << l)) {
//     return dfs(i, l + 1, status, nstatus);
//   }

//  ll result = 0;
//  // skip
//  result = max(result, dfs(i, l + 1, status, nstatus));

//  // right
//  if (l < n - 1 && !(status & (1 << (l + 1)))) {
//    result = max(result, dfs(i, l + 2, status | (1 << (l + 1)), nstatus) +
//                             prices[mat[i][l]][mat[i][l + 1]]);
//  }
//  // under
//  if (i < n - 1 && !(nstatus & (1 << l))) {
//    result = max(result, dfs(i, l + 1, status, nstatus | (1 << l)) +
//                             prices[mat[i][l]][mat[i + 1][l]]);
//  }

//  return result;
//}

// ll check(ll idx, ll status) {
//   if (idx == n) {
//     return 0;
//   } else if (dp[idx][status] != -1) {
//     return dp[idx][status];
//   }

//  return dp[idx][status] = dfs(idx, 0, status, 0);
//}

// int main(void) {
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//  cin >> n;
//  for (ll i = 0; i < n; ++i) {
//    cin.ignore();
//    for (ll l = 0; l < n; ++l) {
//      char c;
//      cin >> c;
//      if (c < 'F') {
//        mat[i][l] = c - 'A';
//      } else {
//        mat[i][l] = 3;
//      }
//    }
//  }

//  memset(dp, -1, sizeof(dp));

//  cout << check(0, 0) << "\n";

//  return 0;
//}