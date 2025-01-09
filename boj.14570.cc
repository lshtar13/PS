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

cll N = 2e5, root = 1;
ll n, k, childs[N + 1][2] = {{}}, bids[N + 1] = {};

ll search(ll node, ll left, ll right) {
  //   cout << node << "\n";
  if (childs[node][0] && childs[node][1]) {
    if (left > right) {
      return search(childs[node][0], left / 2 + left % 2, left / 2);
    } else {
      return search(childs[node][1], right / 2 + right % 2, right / 2);
    }
  } else if (childs[node][0]) {
    return search(childs[node][0], left, right);
  } else if (childs[node][1]) {
    return search(childs[node][1], left, right);
  } else {
    return node;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for (ll i = 1; i <= n; ++i) {
    cin >> childs[i][0] >> childs[i][1];
    childs[i][0] = childs[i][0] < 0 ? 0 : childs[i][0];
    childs[i][1] = childs[i][1] < 0 ? 0 : childs[i][1];
  }
  cin >> k;
  cout << search(root, k / 2 + k % 2, k / 2) << "\n";

  return 0;
}