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

cll N = 1e5;
ll n;

class Node {
public:
  string num;
  Node *childs[2];

  Node() { childs[0] = childs[1] = NULL; }

  void add(string tgt, ll pos) {
    if (pos >= tgt.size()) {
      num = tgt;
      return;
    }

    ll idx = (tgt[pos] - '0');
    if (!childs[idx]) {
      childs[idx] = new Node();
    }

    childs[idx]->add(tgt, pos + 1);
  }

  string search(string tgt, ll pos) {
    if (tgt.size() == pos) {
      
    }
  }
};

string toStr(ll num) {}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Node root;
  cin >> n;
  FOR(i, n) {
    ll num;
    cin >> num;
    root.add()
  }

  return 0;
}