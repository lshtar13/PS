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
ll idxs[N + 1] = {}, segs[N * 10] = {};

ll sum(ll node, ll st, ll en, ll idx) {
  ll mid = (st + en) / 2, result;
  if (idx <= st) {
    result = segs[node];
  } else if (idx > en) {
    result = 0;
  } else {
    result = sum(node * 2, st, mid, idx) + sum(node * 2 + 1, mid + 1, en, idx);
  }

  if (st <= idx && idx <= en) {
    ++segs[node];
  }

  return result;
}

ll solve() {
  ll n, result = 0;
  cin >> n;

  memset(idxs, 0, sizeof(idxs));
  memset(segs, 0, sizeof(segs));
  for (ll num, i = 0; i < n; ++i) {
    cin >> num;
    idxs[num] = i;
  }

  for (ll num, i = 0; i < n; ++i) {
    cin >> num;
    result += sum(1, 0, n - 1, idxs[num]);
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << '\n';
  }

  return 0;
}