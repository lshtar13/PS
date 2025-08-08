#include <bits/stdc++.h>
#include <climits>

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

cll N1 = 1000, N2 = 1000;
ll n1, n2;

class trie {
public:
  bool able, unable, end, ast;
  ll nchild, nasterisk;
  trie *childs[CHAR_MAX] = {};

  trie() {
    able = unable = end = false, ast = false, nchild = 0, nasterisk = 0;
    memset(childs, 0, sizeof(childs));
  }

  ~trie() {
    FOR(c, 0, CHAR_MAX) {
      if (childs[c]) {
        delete childs[c];
      }
    }
  }

  void push(const string &str, ll pos, const bool erasable) {
    if (str.length() == pos) {
      if (erasable) {
        end = true;
      }
      return;
    }

    char c = str[pos];
    if (!childs[c]) {
      childs[c] = new trie();
    }

    if (erasable) {
      childs[c]->able |= true;
    } else {
      childs[c]->ast |= true;
      childs[c]->unable |= true;
    }

    childs[c]->push(str, pos + 1, erasable);
  }

  ll count() {
    ll result = 0;
    FOR(c, 0, CHAR_MAX) {
      if (!childs[c]) {
        continue;
      }

      // if (childs[c]->able && childs[c]->unable) {
      //   result += childs[c]->count();
      //   if (childs[c]->end) {
      //     ++result;
      //   }
      // } else if (childs[c]->able) {
      //   ++result;
      // }

      if (childs[c]->ast) {
        result += childs[c]->count();
        if (childs[c]->end) {
          ++result;
        }
      } else {
        ++result;
      }
    }

    return result;
  }
};

ll solve() {
  trie root;
  string str;

  cin >> n1;
  FOR(i, 0, n1) {
    cin >> str;
    root.push(str, 0, true);
  }

  cin >> n2;
  FOR(i, 0, n2) {
    cin >> str;
    root.push(str, 0, false);
  }

  return root.count();
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}