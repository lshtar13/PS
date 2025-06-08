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

cll N = 1000, M = 2000;
ll n, m;

bool avail(ll choice, ll sign, vll idxs[], ll alts[], bool checked[]) {
  if (idxs[choice].empty()) {
    return true;
  }

  ll psign = idxs[choice][0] / abs(idxs[choice][0]);
  if (psign == sign) {
    return true;
  }

  if (checked[choice]) {
    return false;
  } else {
    checked[choice] = true;
  }

  for (auto &idx : idxs[choice]) {
    ll prv = abs(idx);
    if (!alts[prv]) {
      return false;
    }

    ll asign = alts[prv] / abs(alts[prv]), alt = alts[prv] / asign;
    if (!avail(alt, asign, idxs, alts, checked)) {
      return false;
    }
  }

  for (auto &idx : idxs[choice]) {
    ll prv = abs(idx), asign = alts[prv] / abs(alts[prv]),
       alt = alts[prv] / asign;
    idxs[alt].emplace_back(asign * prv);
    alts[prv] = 0;
  }

  idxs[choice].clear();
  return true;
}

string solve() {
  ll alts[M + 1] = {};
  vll idxs[N + 1];

  for (ll i = 1, a, b, sa, sb; i <= m; ++i) {
    cin >> a >> b;
    sa = a / abs(a), a = abs(a), sb = b / abs(b), b = abs(b);
    bool checked[N + 1] = {};

    if (avail(a, sa, idxs, alts, checked)) {
      idxs[a].emplace_back(i * sa), alts[i] = sb * b;
    }

    memset(checked, 0, sizeof(checked));
    if (avail(b, sb, idxs, alts, checked)) {
      idxs[b].emplace_back(i * sb), alts[i] = sa * a;
    }
  }

  bool checked[N + 1] = {};
  if (!avail(1, 1, idxs, alts, checked)) {
    return "no";
  }

  return "yes";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (cin >> n >> m) {
    cout << solve() << "\n";
  }

  return 0;
}