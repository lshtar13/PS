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

cll N = 1e5, Mod = 1e9 + 7;
ll n, sum = 0;
vpll edges[N];

ll dfs(ll node, ll prv) {
  ll child, w, value = 0, cvalue;
  for (auto &p : edges[node]) {
    tie(child, w) = p;
    if (child == prv) {
      continue;
    }

    cvalue = dfs(child, node);
    sum += ((w * cvalue + w) % Mod) * value + cvalue, sum %= Mod;
    value += w * cvalue + w, value %= Mod;
  }

  return value;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(e, 0, n - 1) {
    ll a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    edges[a].emplace_back(b, w);
    edges[b].emplace_back(a, w);
  }

  sum += dfs(0, 0);
  cout << sum % Mod << "\n";

  return 0;
}