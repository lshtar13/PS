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

cll N = 5e5;
ll n, ranks[N] = {}, seg[10 * N] = {};
vpll infos;

void insert(ll s, ll e, ll node, const ll idx) {
  ++seg[node];
  if (s < e) {
    ll mid = (s + e) / 2;
    if (idx <= mid) {
      insert(s, mid, node * 2, idx);
    } else {
      insert(mid + 1, e, node * 2 + 1, idx);
    }
  }
}

ll find(ll s, ll e, ll node, const ll tgt) {
  if (s >= 0 && e <= tgt) {
    return seg[node];
  } else if (s > tgt) {
    return 0;
  }

  ll mid = (s + e) / 2;
  return find(s, mid, node * 2, tgt) + find(mid + 1, e, node * 2 + 1, tgt);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll abil, i = 0; i < n; ++i) {
    cin >> abil;
    infos.emplace_back(make_pair(abil, i));
  }
  sort(infos.begin(), infos.end(), greater<>());

  for (auto &info : infos) {
    ranks[info.second] = find(0, n - 1, 1, info.second);
    insert(0, n - 1, 1, info.second);
  }

  for (ll i = 0; i < n; ++i) {
    cout << min(i, ranks[i]) + 1 << "\n";
  }

  return 0;
}