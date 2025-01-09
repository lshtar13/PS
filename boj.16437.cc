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

cll N = 123456;
ll n, species[2][N + 1] = {{}}, result = 0; // sheep(0), wolf(1)
stack<pll> wolves;
vvll edges(N + 1);
bool visited[N + 1] = {};

void search(ll node) {
  ll nspecie;
  for (auto child : edges[node]) {
    if (visited[child]) {
      continue;
    }

    visited[child] = true;
    if (species[0][child]) {
      nspecie = species[0][child];
      while (nspecie > 0 && !wolves.empty()) {
        ll _node = wolves.top().first, nwolf = wolves.top().second, _nspecie;
        wolves.pop();

        _nspecie = max(ll(0), nspecie - nwolf);
        nwolf -= nspecie - _nspecie;
        nspecie = _nspecie;

        if (nwolf > 0) {
          wolves.push({_node, nwolf});
        }
      }
      result += nspecie;
      search(child);
    } else {
      nspecie = species[1][child];
      wolves.push({child, nspecie});
      search(child);
      if (!wolves.empty() && wolves.top().first == child) {
        wolves.pop();
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 2; i <= n; ++i) {
    char specie;
    ll nspecie, bridge;
    cin >> specie >> nspecie >> bridge;

    edges[i].emplace_back(bridge);
    edges[bridge].emplace_back(i);

    species[specie == 'W'][i] = nspecie;
  }

  visited[1] = true;
  search(1);

  cout << result << "\n";

  return 0;
}