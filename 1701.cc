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
cll MAX_LEN = 5000;
string str;
ll pi[MAX_LEN + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> str;

  ll len = str.length(), result = 0;
  for (ll st = 0; st < len; ++st) {
    string subStr = str.substr(st);
    memset(pi, 0, sizeof(pi));
    for (ll _pi, i = 1; i < subStr.length(); ++i) {
      _pi = pi[i - 1];
      while (subStr[_pi] != subStr[i] && _pi) {
        _pi = pi[_pi - 1];
      }

      pi[i] = subStr[_pi] == subStr[i] ? _pi + 1 : 0;
      result = max(result, pi[i]);
    }
  }

  cout << result << "\n";

  return 0;
}