#include <algorithm>
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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

typedef tuple<ll, ll, ll> info_t;

cll N = 1e5, M = N - 1, A = N - 1, B = N - 1, T = 1e4, L = 1e4;
ll n, m, nt, gidx = 0, prvs[N] = {}, lengths[N] = {};
vpll edges[N];
bool visited[N] = {}, finished[N] = {};

pll dfs(ll node, vector<bool> &visited) {
  visited[node] = true, finished[node] = true;
  pll result(node, 0);
  for (auto &p : edges[node]) {
    ll av = p.first, w = p.second;
    if (visited[av]) {
      continue;
    }

    prvs[av] = node, lengths[av] = w;
    pll nresult = dfs(av, visited);
    if (nresult.second + w > result.second) {
      result = {nresult.first, nresult.second + w};
    }
  }

  return result;
}

info_t findRoot(ll node) {
  vector<bool> visited0(N), visited1(N);
  ll end0 = dfs(node, visited0).first, end1, diameter;
  prvs[end0] = end0;
  tie(end1, diameter) = dfs(end0, visited1);

  ll half = 0;
  for (ll cur = end1; cur != end0; cur = prvs[cur]) {
    ll pdiff = abs(diameter - half * 2), nhalf = half + lengths[cur], ndiff;
    ndiff = abs(diameter - nhalf * 2);
    if (pdiff < ndiff) {
      return {cur, max(half, diameter - half), diameter};
    } else {
      half = nhalf;
    }
  }

  return {end0, diameter, diameter};
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> nt;
  FOR(i, 0, m) {
    ll a, b, t;
    cin >> a >> b >> t;
    edges[a].emplace_back(b, t);
    edges[b].emplace_back(a, t);
  }

  ll result = 0;
  vll lens, diameters;
  FOR(node, 0, n) {
    if (finished[node]) {
      continue;
    }

    ll root, maxLen, diameter;
    tie(root, maxLen, diameter) = findRoot(node);
    lens.emplace_back(maxLen);
    result = max(result, diameter);
  }
  sort(lens.begin(), lens.end(), greater<ll>());

  if (lens.size() >= 2) {
    result = max(result, lens[0] + lens[1] + nt);
  }
  if (lens.size() >= 3) {
    result = max(result, lens[1] + lens[2] + 2 * nt);
  }

  cout << result << "\n";

  return 0;
}