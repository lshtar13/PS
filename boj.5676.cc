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

cll N = 1e5, K = 1e5;
ll nums[N] = {}, seg[N * 10] = {};

ll update(ll st, ll en, ll node, ll idx, ll num) {
  if (idx < st || en < idx) {
    return seg[node];
  } else if (st == en) {
    return seg[node] = num ? num / abs(num) : 0;
  }

  ll mid = (st + en) / 2, left = update(st, mid, node * 2, idx, num),
     right = update(mid + 1, en, node * 2 + 1, idx, num);

  return seg[node] = left * right;
}

ll query(ll st, ll en, ll node, ll tgt0, ll tgt1) {
  if (tgt0 <= st && en <= tgt1) {
    return seg[node];
  } else if (en < tgt0 || tgt1 < st) {
    return 1;
  }

  ll mid = (st + en) / 2, left = query(st, mid, node * 2, tgt0, tgt1),
     right = query(mid + 1, en, node * 2 + 1, tgt0, tgt1);

  return left * right;
}

void solve(ll n, ll k) {
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
    update(0, n - 1, 1, i, nums[i]);
  }

  char cmd, result;
  for (ll a, b, p, q = 0; q < k; ++q) {
    cin >> cmd >> a >> b;
    switch (cmd) {
    case 'C':
      update(0, n - 1, 1, --a, b);
      break;
    case 'P':
      p = query(0, n - 1, 1, --a, --b);
      if (p > 0) {
        cout << "+";
      } else if (p < 0) {
        cout << "-";
      } else {
        cout << "0";
      }
      break;
    }
  }
  cout << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n, k;
  while (cin >> n >> k) {
    solve(n, k);
  }

  return 0;
}