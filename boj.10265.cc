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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 500, K = 1e4;
ll n, k, owners[N * 2] = {};
bool checked[N * 2] = {};

bool check(ll i, ll l) {
  for (auto idx : {i, l + n}) {
    if (checked[idx]) {
      continue;
    }

    checked[idx] = true;
    if (owners[idx] == -1) {
      owners[idx] = i * n + l;
      return true;
    } else if (check(owners[idx] / n, owners[idx] % n)) {
      owners[idx] = i * n + l;
      return true;
    }
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(owners, -1, sizeof(owners));
  cin >> n >> k;
  FOR(s, k) {
    ll i, l;
    cin >> i >> l;
    --i, --l;

    memset(checked, 0, sizeof(checked));
    check(i, l);
  }

  ll result = 0;
  FOR(i, n * 2) { result += bool(owners[i] != -1); }
  cout << result << "\n";

  return 0;
}