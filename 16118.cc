#include <bits/stdc++.h>
#include <climits>
#include <iostream>

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

typedef pair<double, ll> info;

cll N = 4000, M = 1e5, INF = LLONG_MAX;
ll n, m;
vll dist0(N, INF);
vvll dist1(2, vll(N, INF));
vpll edges[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  ll a, b, d;
  while (m--) {
    cin >> a >> b >> d;
    --a, --b, d *= 2;
    edges[a].emplace_back(make_pair(b, d));
    edges[b].emplace_back(make_pair(a, d));
  }

  pqpll pq;
  pq.push(make_pair(0, 0));
  dist0[0] = 0;
  while (!pq.empty()) {
    ll dist = -pq.top().first, node = pq.top().second;
    pq.pop();

    if (dist0[node] < dist) {
      continue;
    }

    for (auto &p : edges[node]) {
      ll av = p.first, d = p.second;
      if (dist0[av] > d + dist) {
        dist0[av] = d + dist;
        pq.push(make_pair(-(d + dist), av));
      }
    }
  }

  pq.push(make_pair(0, 1));
  while (!pq.empty()) {
    ll dist = -pq.top().first, node = pq.top().second / 2,
       state = pq.top().second % 2;
    pq.pop();

    if (dist1[!state][node] < dist) {
      continue;
    }

    for (auto &p : edges[node]) {
      ll av = p.first, d = p.second;
      d = state ? d / 2 : d * 2;
      if (dist1[state][av] > d + dist) {
        dist1[state][av] = d + dist;
        pq.push(make_pair(-(d + dist), av * 2 + !state));
      }
    }
  }

  ll result = 0;
  for (ll i = 1; i < n; ++i) {
    result += dist0[i] < min(dist1[0][i], dist1[1][i]);
    // cout << dist0[i] << " " << min(dist1[0][i], dist1[1][i]) << "\n";
  }
  cout << result << "\n";

  return 0;
}