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
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

cll LEN = 1e6;
string s, t;
deque<ll> indexes[26];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> t;

  for (ll i = 0; i < t.size(); ++i) {
    indexes[t[i] - 'a'].emplace_back(i);
  }

  ll result = 0, prv = -1;
  for (ll i = 0; i < s.size(); ++i) {
    char c = s[i] - 'a';
    auto &index = indexes[c];
    if (index.empty()) {
      cout << -1 << '\n';
      goto END;
    }

  AGAIN:
    auto it = upper_bound(index.begin(), index.end(), prv);
    if (it == index.end()) {
      ++result, prv = -1;
      goto AGAIN;
    }

    prv = *it;
  }

  cout << result + 1 << '\n';

END:

  return 0;
}