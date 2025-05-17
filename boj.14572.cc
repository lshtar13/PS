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

cll N = 1e5, K = 30, D = 1e9;
ll n, k, d, comp[K] = {}, nmember = 0;
pll abils[N] = {};
bool algos[N][K] = {{}};

ll join(ll idx) {
  ++nmember;
  idx = abils[idx].second;
  pll result = {0, 0};
  for (ll algo = 0; algo < k; ++algo) {
    comp[algo] += algos[idx][algo];

    if (comp[algo]) {
      ++result.first;
    }

    if (comp[algo] == nmember) {
      ++result.second;
    }
  }

  return (result.first - result.second) * nmember;
}

ll disjoin(ll idx) {
  --nmember;
  idx = abils[idx].second;
  pll result = {0, 0};
  for (ll algo = 0; algo < k; ++algo) {
    comp[algo] -= algos[idx][algo];

    if (comp[algo]) {
      ++result.first;
    }

    if (comp[algo] == nmember) {
      ++result.second;
    }
  }

  return (result.first - result.second) * nmember;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k >> d;
  for (ll i = 0, nalgo, abil; i < n; ++i) {
    cin >> nalgo >> abil;
    abils[i] = {abil, i};
    for (ll l = 0, algo; l < nalgo; ++l) {
      cin >> algo;
      algos[i][--algo] = true;
    }
  }

  sort(abils, abils + n);

  ll result = join(0);
  for (ll st = 0, en = 1, nresult; en < n; ++en) {
    while (st < en && abils[en].first - abils[st].first > d) {
      disjoin(st++);
    }

    result = max(result, join(en));
  }

  cout << result << "\n";

  return 0;
}