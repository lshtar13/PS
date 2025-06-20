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

cll N = 5e5, Num = 1e5, M = 5e5;
ll n, nums[N] = {}, segs[N * 20] = {}, m;

void update(ll node, ll st, ll en, ll left, ll right, ll value) {
  if (right < st || left > en) {
    return;
  } else if (left <= st && right >= en) {
    segs[node] ^= value;
    return;
  }

  ll mid = (st + en) / 2;
  update(node * 2, st, mid, left, right, value);
  update(node * 2 + 1, mid + 1, en, left, right, value);
}

ll query(ll node, ll st, ll en, ll idx) {
  if (st == en) {
    return segs[node];
  }

  ll mid = (st + en) / 2;
  if (idx <= mid) {
    return segs[node] ^ query(node * 2, st, mid, idx);
  } else {
    return segs[node] ^ query(node * 2 + 1, mid + 1, en, idx);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) { cin >> nums[i]; }
  cin >> m;
  FOR(i, m) {
    ll t, a, b, c;
    cin >> t >> a;
    if (t == 1) {
      cin >> b >> c;
      update(1, 0, n - 1, a, b, c);
    } else {
      cout << (nums[a] ^ query(1, 0, n - 1, a)) << "\n";
    }
  }

  return 0;
}