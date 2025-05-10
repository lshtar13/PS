#include <bits/stdc++.h>
#include <ratio>
#include <string>

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
typedef vector<vll> vvll;

cll N = 10;
ll n;
bool chess[N][N] = {{}};
ll lines0[2 * N] = {}, lines1[2 * N] = {};

inline pll getline(ll i, ll l) { return {i + l, l - i}; }

bool avail(ll i, ll l) {
  ll k0, k1;
  tie(k0, k1) = getline(i, l);

  return chess[i][l] && !lines0[k0] && !lines1[k1];
}

ll search0(ll num) {
  ll i = num / n, l = num % n;
  if (num >= n * n) {
    return 0;
  } else if (!avail(i, l)) {
    return search0(num + 2);
  }

  ll result = 0, k0, k1;
  result = max(result, search0(num + 2));
  tie(k0, k1) = getline(i, l);
  ++lines0[k0], ++lines1[k1];
  result = max(result, search0(num + 2) + 1);
  --lines0[k0], --lines1[k1];

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    for (ll l = 0; l < n; ++l) {
      cin >> chess[i][l];
    }
  }

  cout << search0(0) + search0(1) << "\n";

  return 0;
}