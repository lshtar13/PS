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

cll N = 2e5, INF = 1e9 + 7;
ll n, seg[N * 20] = {}, nseg[N * 20] = {};

ll search(ll tgt0, ll tgt1, ll st, ll en, ll node, ll arr[]) {
  if (tgt0 <= st && en <= tgt1) {
    return arr[node];
  } else if (en < tgt0 || tgt1 < st) {
    return 0;
  }

  ll mid = (st + en) / 2, left = search(tgt0, tgt1, st, mid, node * 2, arr),
     right = search(tgt0, tgt1, mid + 1, en, node * 2 + 1, arr);
  return left + right;
}

void update(ll idx, ll num, ll st, ll en, ll node, ll arr[]) {
  arr[node] = arr[node] + num;
  if (st == en) {
    return;
  }

  ll mid = (st + en) / 2;
  if (idx <= mid) {
    update(idx, num, st, mid, node * 2, arr);
  } else {
    update(idx, num, mid + 1, en, node * 2 + 1, arr);
  }

  return;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  ll result = 1;
  for (ll left, right, nleft, nright, dist, num, i = 0; i < n; ++i) {
    cin >> num;

    left = search(0, num, 0, N - 1, 1, seg);
    right = search(num, N - 1, 0, N - 1, 1, seg);
    nleft = search(0, num, 0, N - 1, 1, nseg);
    nright = search(num, N - 1, 0, N - 1, 1, nseg);

    ll ldist = abs(num * nleft - left), rdist = abs(right - num * nright);
    dist = (ldist + rdist) % INF;
    result = i ? (result * dist) % INF : 1;

    update(num, num, 0, N - 1, 1, seg);
    update(num, 1, 0, N - 1, 1, nseg);
  }

  cout << result << "\n";

  return 0;
}