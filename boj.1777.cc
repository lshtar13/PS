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

cll N = 1e5;
ll n, nums[N + 1] = {}, invSeq[N + 1] = {}, seg[N * 17] = {};

ll update(ll st, ll en, ll node, ll idx, ll num) {
  if (idx < st || en < idx) {
    return seg[node];
  } else if (st == en) {
    return seg[node] = num;
  }

  ll mid = (st + en) / 2;
  return seg[node] = update(st, mid, 2 * node, idx, num) +
                     update(mid + 1, en, 2 * node + 1, idx, num);
}

ll query(ll st, ll en, ll node, ll idx0, ll idx1) {
  if (idx0 <= st && en <= idx1) {
    return seg[node];
  } else if (idx1 < st || en < idx0) {
    return 0;
  }

  ll mid = (st + en) / 2;
  return query(st, mid, 2 * node, idx0, idx1) +
         query(mid + 1, en, 2 * node + 1, idx0, idx1);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> invSeq[i];
    update(1, n, 1, i, 1);
  }

  for (ll inv, num = n; num > 0; --num) {
    inv = invSeq[num] + 1;
    // 1 ~8, 8

    ll st = 1, en = n, pos;
    while (st <= en) {
      ll mid = (st + en) / 2, sum = query(1, n, 1, mid, n);
      if (sum >= inv) {
        pos = mid, st = mid + 1;
      } else {
        en = mid - 1;
      }
    }

    nums[pos] = num;
    update(1, n, 1, pos, 0);
  }

  for (ll i = 1; i <= n; ++i) {
    cout << nums[i] << " ";
  }
  cout << "\n";

  return 0;
}