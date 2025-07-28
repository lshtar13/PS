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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 50, Num = 1000;
ll n, nums[N] = {}, mates[N] = {};
bool isNotPrime[Num * 2 + 1] = {}, visited[N] = {};
vll edges[N];

bool check(ll idx) {
  for (auto &av : edges[idx]) {
    if (visited[av]) {
      continue;
    }

    visited[av] = true;
    if (mates[av] == -1 || check(mates[av])) {
      mates[av] = idx, mates[idx] = av;
      return true;
    }
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, 0, n) { cin >> nums[i]; }

  // find prime number
  FOR(num, 2, Num * 2 + 1) {
    if (isNotPrime[num]) {
      continue;
    }
    for (ll nnum = num * 2; nnum <= Num * 2; nnum += num) {
      isNotPrime[nnum] = true;
    }
  }

  // find adjacency
  FOR(a, 0, n) FOR(b, a + 1, n) {
    ll sum = nums[a] + nums[b];
    if (!isNotPrime[sum]) {
      edges[a].emplace_back(b);
      edges[b].emplace_back(a);
    }
  }

  vll results;
  for (auto &mate : edges[0]) {
    memset(mates, -1, sizeof(mates));
    mates[0] = mate, mates[mate] = 0;

    results.push_back(nums[mate]);
    FOR(idx, 1, n) {
      memset(visited, 0, sizeof(visited));
      visited[0] = visited[mate] = true;
      if (mates[idx] == -1 && !check(idx)) {
        results.pop_back();
        break;
      }
    }
  }

  sort(results.begin(), results.end());
  if (!results.empty()) {
    for (auto &num : results) {
      cout << num << " ";
    }
  } else {
    cout << "-1";
  }
  cout << "\n";

  return 0;
}