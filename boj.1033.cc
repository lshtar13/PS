#include <algorithm>
#include <bits/stdc++.h>
#include <tuple>

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

typedef tuple<ll, ll, ll, ll> info_t;

cll N = 10;
ll n;
vll mass(N, 1), edges[N];
vector<info_t> inputs;

void propagate(ll node, ll prv, ll weight) {
  mass[node] *= weight;
  for (auto &av : edges[node]) {
    if (av == prv) {
      continue;
    }
    propagate(av, node, weight);
  }
}

ll findGcd(ll num, ll idx) {
  if (idx == n) {
    return num;
  } else {
    return findGcd(gcd(num, mass[idx]), idx + 1);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  mass.resize(n);
  for (ll a, b, p, q, c, i = 0; i < n - 1; ++i) {
    cin >> a >> b >> p >> q;
    edges[a].emplace_back(b);
    edges[b].emplace_back(a);
    c = gcd(p, q);
    inputs.emplace_back(make_tuple(a, b, p / c, q / c));
  }

  for (auto &input : inputs) {
    ll a, b, p, q, c;
    tie(a, b, p, q) = input;
    propagate(a, b, p);
    propagate(b, a, q);

    c = findGcd(mass[0], 1);
    for (auto &m : mass) {
      m /= c;
    }
  }

  for (auto &m : mass) {
    cout << m << " ";
  }
  cout << "\n";

  return 0;
}