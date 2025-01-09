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

cll N = 1e5, M = 1e5, K = 1e5;
ll n, m, k, degree[N] = {};
vvll childs(N), parents(N);

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m >> k;
  FOR1(i, m) {
    ll x, y;
    cin >> x >> y;
    childs[--x].emplace_back(--y);
    parents[y].emplace_back(x);
    ++degree[y];
  }

  set<ll> avail;
  multiset<ll> constructed;
  FOR1(i, n) {
    if (!degree[i]) {
      avail.insert(i);
    }
  }

  FOR1(i, k) {
    ll type, a;
    cin >> type >> a;
    --type, --a;
    if (!type) {
      if (avail.find(a) == avail.end()) {
        cout << "Lier!" << "\n";
        goto END;
      } else {
        constructed.insert(a);
        for (auto &child : childs[a]) {
          if (!avail.count(child) && constructed.count(a) == 1 &&
              !--degree[child]) {
            avail.insert(child);
          }
        }
      }
    } else {
      if (constructed.find(a) == constructed.end()) {
        cout << "Lier!" << "\n";
        goto END;
      } else {
        auto it = constructed.find(a);
        auto cnt = constructed.count(a);
        if (cnt == 0) {
          continue;
          //   goto PRINT;
        }
        constructed.erase(it);

        if (cnt != 1) {
          continue;
          //   goto PRINT;
        }
        for (auto &child : childs[a]) {
          if (avail.erase(child)) {
            ++degree[child];
          }
        }
      }
    }
    //   PRINT:
    //     for (auto &_avail : avail) {
    //       cout << _avail << " ";
    //     }
    //     cout << "\n";
    //     for (auto &_const : constructed) {
    //       cout << _const << " ";
    //     }
    //     cout << "\n";
  }

  cout << "King-God-Emperor" << "\n";

END:

  return 0;
}