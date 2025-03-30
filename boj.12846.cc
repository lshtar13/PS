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

cll N = 1e5, T = 1e6;
ll n, segs[N * 10] = {}, salaries[N + 1] = {};

ll update(ll node, ll idx0, ll idx1, cll idx) {
  if (idx < idx0 || idx > idx1) {
    return segs[node];
  } else if (idx0 == idx1) {
    return segs[node] = idx;
  }

  ll mid = (idx0 + idx1) / 2;
  ll left = update(node * 2, idx0, mid, idx),
     right = update(node * 2 + 1, mid + 1, idx1, idx);

  if (salaries[left] < salaries[right]) {
    return segs[node] = left;
  } else {
    return segs[node] = right;
  }
}

ll query(ll node, ll idx0, ll idx1, cll st, cll en) {
  if (en < idx0 || st > idx1) {
    return 0;
  } else if (st <= idx0 && en >= idx1) {
    return segs[node];
  }

  ll mid = (idx0 + idx1) / 2;
  ll left = query(node * 2, idx0, mid, st, en),
     right = query(node * 2 + 1, mid + 1, idx1, st, en);
  if (salaries[left] < salaries[right]) {
    return left;
  } else {
    return right;
  }
}

ll findMax(ll l, ll r) {
  if (l > r) {
    return 0;
  }

  ll minIdx = query(1, 1, n, l, r),
     totalSalary = salaries[minIdx] * (r - l + 1);
  totalSalary = max(totalSalary, findMax(l, minIdx - 1));
  totalSalary = max(totalSalary, findMax(minIdx + 1, r));

  return totalSalary;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  salaries[0] = T + 1;

  cin >> n;
  ll result = 0;
  for (ll i = 1; i <= n; ++i) {
    cin >> salaries[i];
    update(1, 1, n, i);
  }

  cout << findMax(1, n) << "\n";

  return 0;
}