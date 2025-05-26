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

typedef tuple<ll, ll, ll> info_t;

cll N = 2e5, Q = 2e5;
ll n, q, childs[N + 1] = {}, parents[N + 1] = {}, dijs[N + 1] = {};

// offline query
ll findParent(ll node) {
  if (node == dijs[node]) {
    return node;
  }

  return dijs[node] = findParent(dijs[node]);
}

void merge(ll node0, ll node1) {
  ll parent0 = findParent(node0), parent1 = findParent(node1);
  dijs[parent0] = parent1;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> q;
  parents[1] = 1;
  for (ll i = 2; i <= n; ++i) {
    cin >> parents[i];
    dijs[i] = i;
  }

  stack<info_t> queries;
  for (ll i = 0, x, a, b; i < n - 1 + q; ++i) {
    cin >> x >> a;
    if (x == 1) {
      cin >> b;
    } else {
      b = 0;
    }

    queries.push({x, a, b});
  }

  stack<string> answers;
  for (ll x, a, b; !queries.empty();) {
    tie(x, a, b) = queries.top();
    queries.pop();

    if (x == 0) {
      ll node0 = a, node1 = parents[node0];
      merge(node0, node1);
    } else {
      ll parent0 = findParent(a), parent1 = findParent(b);
      if (parent0 == parent1) {
        answers.push("YES\n");
      } else {
        answers.push("NO\n");
      }
    }
  }

  while (!answers.empty()) {
    cout << answers.top();
    answers.pop();
  }

  return 0;
}