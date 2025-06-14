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

cll N = 1e5, K = 1e5;
ll n, k, segs[N * 10] = {};

ll update(ll node, ll left, ll right, ll idx, ll num) {
  if (idx < left || idx > right) {
    return segs[node];
  } else if (left == right) {
    return segs[node] += num;
  }

  ll mid = (left + right) / 2;
  return segs[node] = update(node * 2, left, mid, idx, num) +
                      update(node * 2 + 1, mid + 1, right, idx, num);
}

ll query(ll node, ll left, ll right, ll amnt) {
  if (left == right) {
    return left;
  }

  ll lamnt = segs[node * 2], ramnt = segs[node * 2 + 1],
     mid = (left + right) / 2;

  if (lamnt < amnt) {
    return query(node * 2 + 1, mid + 1, right, amnt - lamnt);
  } else {
    return query(node * 2, left, mid, amnt);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (ll i = 0; i < n; ++i) {
    update(1, 0, n - 1, i, 1);
  }

  vll results;
  for (ll nleft = n, tocheck = k; nleft > 0; --nleft, tocheck += k - 1) {
    if (tocheck > nleft) {
      tocheck %= nleft;
      if (tocheck == 0) {
        tocheck = nleft;
      }
    }

    ll idx = query(1, 0, n - 1, tocheck);
    update(1, 0, n - 1, idx, -1);
    results.emplace_back(idx + 1);
  }

  cout << "<";
  for (ll i = 0; i < results.size() - 1; ++i) {
    cout << results[i] << ", ";
  }
  cout << results[results.size() - 1] << ">\n";

  return 0;
}