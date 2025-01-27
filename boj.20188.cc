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

cll N = 3e5;
ll n, depths[N] = {}, parents[N] = {}, nchilds[N] = {};
vll edges[N];

void findChild(ll node) {
  for (auto &av : edges[node]) {
    if (av == parents[node]) {
      continue;
    }

    parents[av] = node, depths[av] = depths[node] + 1;
    findChild(av);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll a, b, i = 0; i < n - 1; ++i) {
    cin >> a >> b;
    --a, --b;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
  }

  findChild(0);

  ll result = 0;
  for (ll a = 0; a < n; ++a) {
    for (ll v, b = a + 1; b < n; ++b) {
      v = variety(a, b);
      result += v;
    }
  }

  cout << result << "\n";

  return 0;
}