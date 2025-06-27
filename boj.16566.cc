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

cll N = 4e6, M = N, K = 1e4;
ll n, m, k;
set<ll> nums;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  FOR(i, m) {
    ll num;
    cin >> num;
    nums.insert(num);
  }

  FOR(i, k) {
    ll num;
    cin >> num;
    num = *nums.upper_bound(num);
    cout << num << "\n";
    nums.extract(num);
  }

  return 0;
}