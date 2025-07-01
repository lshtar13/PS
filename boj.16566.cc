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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 4e6, M = 4e6, K = 1e4;
ll n, m, k, cards[M] = {}, parents[N + 2] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  FOR(i, m) { cin >> cards[i]; }
  sort(cards, cards + n);
  set<ll> s(cards, cards + n);

  FOR(i, k) {
    ll num;
    cin >> num;
    cout << (num = *s.upper_bound(num)) << "\n";
    s.extract(num);
  }

  return 0;
}