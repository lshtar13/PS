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

cll S = 1e6, M = 1e5;
string str;
ll m, pi[S] = {};

ll F(ll idx) { return 0; }

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str >> m;
  reverse(str.begin(), str.end());
  FOR(i, 1, str.length()) {
    ll prv = pi[i - 1];
    while (prv && str[i] != str[prv]) {
      prv = pi[prv - 1];
    }

    pi[i] = str[i] == str[prv] ? prv + 1 : 0;
  }

  


  return 0;
}