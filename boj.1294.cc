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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

typedef tuple<ll, char, ll, ll> info_t;

cll N = 20;
ll n, heads[N] = {}, pts[N] = {}, totalLength = 0;
string words[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin.ignore();
  FOR(w, 0, n) {
    getline(cin, words[w]);
    totalLength += words[w].length();
  }

  ll cur = 0;
  string result;
  while (cur < totalLength) {
    char c = 'Z' + 1;
    FOR(w, 0, n) {
      if (pts[w] >= words[w].size()) {
        continue;
      }

      c = min(c, words[w][pts[w]]);
    }

    vll entities;
    FOR(w, 0, n) {
      if (words[w][pts[w]] == c) {
        ++pts[w];
        entities.emplace_back(w);
      }
    }

    if (entities.size() == 1) {
      heads[entities[0]] = pts[entities[0]];
      FOR(w, 0, n) { pts[w] = heads[w]; }
    }

    ++cur;
    result.push_back(c);
  }

  cout << result << "\n";

  return 0;
}