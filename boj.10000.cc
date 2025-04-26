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

cll N = 3e5;
ll n;
pll infos[N];
priority_queue<pll, vpll, greater<pll>> pq;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0, x, r; i < n; ++i) {
    cin >> x >> r;
    infos[i] = {x - r, x + r};
  }
  sort(infos, infos + n);

  ll result = 2;
  pq.push({infos[0].second, infos[0].first});
  for (ll i = 1, st, en; i < n; ++i) {
    tie(en, st) = infos[i];

    for (ll st0, en0; !pq.empty();) {
      tie(en0, st0) = pq.top();
      if (en0 < st) {
        pq.pop();
      }else{
        
      }
    }
  }

  return 0;
}