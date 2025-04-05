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

cll N = 1e5, M = 1e5;
ll n, m;

ll solve() {
  cin >> n >> m;

  vll parents(n, -1);
  vvll edges(n);
  vector<bool> finished(n, false);

  for (ll i = 0, a, b; i < m; ++i) {
    cin >> a >> b;
    --a, --b;
    edges[a].push_back(b);
  }

  stack<ll> s;
  for (ll i = 0; i < n; ++i) {
    if (finished[i]) {
      continue;
    }

    s.push(i);
    parents[i] = i;
    for(auto &av: edges[s.top()]){
        if(parents[av] !=av)
    }
  }

  ll result = 0;

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}