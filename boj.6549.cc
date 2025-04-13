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

cll N = 1e5, H = 1e9;
ll n, heights[N + 1] = {}, segs[N * 10] = {};

ll update(ll node, ll idx0, ll idx1, ll idx) {
  if (idx < idx0 || idx > idx1) {
    return segs[node];
  } else if (idx0 == idx1) {
    return segs[node] = idx;
  }

  ll mid = (idx0 + idx1) / 2, left = update(node * 2, idx0, mid, idx),
     right = update(node * 2 + 1, mid + 1, idx1, idx);

  if (heights[left] < heights[right]) {
    return segs[node] = left;
  } else {
    return segs[node] = right;
  }
}

ll query(ll node, ll idx0, ll idx1, ll st, ll en) {
  if (idx1 < st || idx0 > en) {
    return 0;
  } else if (idx0 >= st && idx1 <= en) {
    return segs[node];
  }

  ll mid = (idx0 + idx1) / 2, left = query(node * 2, idx0, mid, st, en),
     right = query(node * 2 + 1, mid + 1, idx1, st, en);
  if (heights[left] < heights[right]) {
    return left;
  } else {
    return right;
  }
}

void initialize() {
  memset(heights, 0, sizeof(heights));
  memset(segs, 0, sizeof(segs));

  heights[0] = H + 1;
  update(1, 0, n, 0);
}

ll findMax(ll st, ll en) {
  if (st == en) {
    return heights[st];
  } else if (st > en) {
    return 0;
  }

  ll minIdx = query(1, 0, n, st, en);
  ll result = heights[minIdx] * (en - st + 1);
  result = max(result, findMax(st, minIdx - 1));
  result = max(result, findMax(minIdx + 1, en));

  return result;
}

ll solve() {
  initialize();
  for (ll i = 1; i <= n; ++i) {
    cin >> heights[i];
    update(1, 0, n, i);
  }

  return findMax(1, n);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (; cin >> n && n;) {
    cout << solve() << '\n';
  }

  return 0;
}