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

cll N = 1e5;
ll n, inputs[N] = {}, segs[N * 10] = {}, invs[2][N] = {{}};

ll insert(ll node, ll idx0, ll idx1, cll num) {
  if (num < idx0 || num > idx1) {
    return segs[node];
  } else if (idx0 == idx1) {
    return ++segs[node];
  }

  ll mid = (idx0 + idx1) / 2;
  return segs[node] = insert(node * 2, idx0, mid, num) +
                      insert(node * 2 + 1, mid + 1, idx1, num);
}

ll search0(ll node, ll idx0, ll idx1, cll num, bool isGreat) {
  if (isGreat) {
    if (idx1 <= num) {
      return 0;
    } else if (idx0 > num) {
      return segs[node];
    }
  } else {
    if (idx0 >= num) {
      return 0;
    } else if (idx1 < num) {
      return segs[node];
    }
  }

  ll mid = (idx0 + idx1) / 2;
  return search0(node * 2, idx0, mid, num, isGreat) +
         search0(node * 2 + 1, mid + 1, idx1, num, isGreat);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // segment tree
  // seg[0] ==> 순방향
  // seg[1] ==> 역방향
  // invs[0][i] * invs[1][i]

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> inputs[i];
    invs[0][i] = search0(1, 1, n, inputs[i], true);
    insert(1, 1, n, inputs[i]);
  }
  memset(segs, 0, sizeof(segs));
  for (ll i = n - 1; i >= 0; --i) {
    invs[1][i] = search0(1, 1, n, inputs[i], false);
    insert(1, 1, n, inputs[i]);
  }

  ll result = 0;
  for (ll i = 0; i < n; ++i) {
    result += invs[0][i] * invs[1][i];
  }

  cout << result << "\n";

  return 0;
}