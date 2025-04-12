#include <bits/stdc++.h>
#include <cstddef>

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

cll C = 4000, N = 4000, Q = 20000;
ll c, n, q;
unordered_set<string> names;

class node {
public:
  char c;
  map<char, node *> childs;
  bool isEnd{};

  node() { c = 0; }

  node(char alpha) { c = alpha; }

  void add(string &word, ll pos) {
    if (word.length() == pos) {
      isEnd = true;
      return;
    }

    char tgt = word[pos];
    if (!childs[tgt]) {
      childs[tgt] = new node(tgt);
    }
    childs[tgt]->add(word, ++pos);
  }

  bool search(string &word, ll pos) {
    if (pos == word.length()) {
      return false;
    } else if (isEnd && names.count(word.substr(pos))) {
      return true;
    }

    char tgt = word[pos];
    if (childs[tgt]) {
      return childs[tgt]->search(word, ++pos);
    }

    return false;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  node *colors = new node();

  cin >> c >> n;
  for (ll i = 0; i < c; ++i) {
    string color;
    cin >> color;
    colors->add(color, 0);
  }
  for (ll i = 0; i < n; ++i) {
    string name;
    cin >> name;
    names.insert(name);
  }

  cin >> q;
  for (ll i = 0, pos, under; i < q; ++i) {
    string team;
    cin >> team;

    if (colors->search(team, 0)) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}