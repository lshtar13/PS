#include <bits/stdc++.h>
#include <string>
#include <unordered_set>

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

cll N = 1e5, K = 30;
ll n, k, nums[N + 1] = {}, m;
vll edges[N + 1];
unordered_set<ll> times;
map<ll, ll> indexes;

string find(ll tgt) {
  ll prvs[N + 1] = {0, -1};
  qll q;
  q.push(1);
  while (!q.empty()) {
    ll node = q.front();
    q.pop();

    if (node == tgt) {
      break;
    }

    for (auto &av : edges[node]) {
      if (prvs[av]) {
        continue;
      }

      q.push(av);
      prvs[av] = node;
    }
  }

  string result;
  if (!prvs[tgt]) {
    result = "-1";
  } else {
    while (tgt != -1) {
      result = to_string(tgt) + " " + result;
      tgt = prvs[tgt];
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (ll i = 1; i <= n; ++i) {
    string str;
    cin >> str;
    for (ll l = 0; l < k; ++l) {
      nums[i] += (1 << l) * (str[k - 1 - l] - '0');
    }

    indexes[nums[i]] = i;
  }

  for (ll i = 0; i < n; ++i) {
    times.insert(1 << i);
  }

  for (ll i = 1; i <= n; ++i) {
    for (ll num, l = 0; l < k; ++l) {
      num = nums[i] ^ (1 << l);
      if (indexes.find(num) != indexes.end()) {
        edges[i].emplace_back(indexes[num]);
      }
    }
  }

  cin >> m;
  for (ll i = 0, tgt; i < m; ++i) {
    cin >> tgt;
    cout << find(tgt) << '\n';
  }

  return 0;
}