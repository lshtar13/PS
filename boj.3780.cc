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

cll N = 2e4, Mod = 1e3;
ll n, parents[N + 1] = {}, dists[N + 1] = {};

ll findParent(ll node) {
  if (node == parents[node]) {
    return node;
  }

  ll prv = parents[node];
  parents[node] = findParent(prv);
  dists[node] += dists[prv];

  return parents[node];
}

void merge(ll a, ll b) {
  ll parent = findParent(b);
  parents[a] = parent, dists[a] = abs(a - b) % Mod + dists[b];
}

// union find

void solve() {
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    parents[i] = i, dists[i] = 0;
  }

  while (true) {
    cin.ignore();

    char inst;
    ll i, j;
    cin >> inst;
    if (inst == 'O') {
      break;
    } else if (inst == 'E') {
      cin >> i;
      findParent(i);
      cout << dists[i] << "\n";
    } else if (inst == 'I') {
      cin >> i >> j;
      merge(i, j);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}