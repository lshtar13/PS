#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
typedef queue<ll> qll;
typedef queue<pll> qpll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef priority_queue<ll, vll, greater<ll>> pqgll;
typedef priority_queue<pll, vpll, greater<pll>> pqgpll;
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

cll N = 1e5;
ll n, nseats[N] = {}, nseat = 1;
pqgpll users, nonavail;
pqgll avail;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll p, q, i = 0; i < n; ++i) {
    cin >> p >> q;
    users.push(make_pair(p, q));
  }

  avail.push(0);
  while (!users.empty()) {
    ll p = users.top().first, q = users.top().second;
    users.pop();
    while (!nonavail.empty() && nonavail.top().first <= p) {
      avail.push(nonavail.top().second);
      nonavail.pop();
    }

    if (avail.empty()) {
      avail.push(nseat++);
    }

    ++nseats[avail.top()];
    nonavail.push(make_pair(q, avail.top()));
    avail.pop();
  }

  cout << nseat << "\n";
  for (ll i = 0; i < nseat; ++i) {
    cout << nseats[i] << " ";
  }

  return 0;
}