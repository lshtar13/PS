#include <bits/stdc++.h>
#include <queue>

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

cll K = 100, N = 1e5;
ll k, n, primes[K];
set<ll> visited;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k >> n;
  for (ll i = 0; i < k; ++i) {
    cin >> primes[i];
  }

  priority_queue<ll, vector<ll>, greater<ll>> pq;
  pq.push(1);
  for (ll i = 0, prv = 0, minNum; i < n;) {
    minNum = pq.top();
    pq.pop();

    if (prv == minNum) {
      continue;
    }
    prv = minNum, ++i;

    for (ll l = 0, num; l < k; ++l) {
      num = minNum * primes[l];
      pq.push(num);
    }
  }

  cout << pq.top() << "\n";

  return 0;
}