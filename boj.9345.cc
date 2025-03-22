#include <algorithm>
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

cll MIN = 0, MAX = 1, N = 1e5, K = 5e4, INF = N;
ll n, k, dvds[N] = {}, segs[2][N * 10] = {{}};

void fillSeg(ll node, ll left, ll right) {
  segs[MAX][node] = right;
  segs[MIN][node] = left;

  if (left == right) {
    return;
  }

  ll mid = (left + right) / 2;
  fillSeg(node * 2, left, mid);
  fillSeg(node * 2 + 1, mid + 1, right);
}

pll update(ll node, ll left, ll right, ll idx, ll num) {
  if (idx < left || idx > right) {
    return {segs[MIN][node], segs[MAX][node]};
  } else if (left == right) {
    segs[MIN][node] = segs[MAX][node] = num;
    return {num, num};
  }

  ll mid = (left + right) / 2;
  pll lResult = update(node * 2, left, mid, idx, num);
  pll rResult = update(node * 2 + 1, mid + 1, right, idx, num);

  return {segs[MIN][node] = min(lResult.first, rResult.first),
          segs[MAX][node] = max(lResult.second, rResult.second)};
}

pll query(ll node, ll left, ll right, cll st, cll en) {
  if (en < left || st > right) {
    return {INF, -1};
  } else if (st <= left && right <= en) {
    return {segs[MIN][node], segs[MAX][node]};
  }

  ll mid = (left + right) / 2;
  auto lResult = query(node * 2, left, mid, st, en),
       rResult = query(node * 2 + 1, mid + 1, right, st, en);

  return {min(lResult.first, rResult.first),
          max(lResult.second, rResult.second)};
}

void solve() {
  cin >> n >> k;

  for (ll i = 0; i < n; ++i) {
    dvds[i] = i;
  }
  fillSeg(1, 0, n - 1);

  for (ll q, a, b, minV, maxV, incident = 0; incident < k; ++incident) {
    cin >> q >> a >> b;
    if (!q) {
      update(1, 0, n - 1, a, dvds[b]);
      update(1, 0, n - 1, b, dvds[a]);
      swap(dvds[a], dvds[b]);
    } else {
      tie(minV, maxV) = query(1, 0, n - 1, a, b);
      if (minV == a && maxV == b) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}