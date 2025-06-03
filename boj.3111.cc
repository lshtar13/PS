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

cll A = 25, T = 3e5;
char src[A + 1] = {}, tgt[T + 1] = {};
ll a, t, pi[A] = {};
bool deprecated[T] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // kmp, stack
  cin >> src >> tgt;
  a = strlen(src), t = strlen(tgt);

  // get pi;
  for (ll i = 1, prv; i < a; ++i) {
    prv = pi[i - 1];
    while (prv && src[prv] != src[i]) {
      prv = pi[prv - 1];
    }

    if (src[prv] == src[i]) {
      pi[i] = prv + 1;
    } else {
      pi[i] = 0;
    }
  }

  deque<char> prefix, infix, postfix;
  for (ll i = 0; i < t; ++i) {
    infix.emplace_back(tgt[i]);
  }

  while (!infix.empty()) {
    stack<char> temp;
    prefix.emplace_back(infix.front());
    infix.pop_front();

    for (ll i = a - 1; i >= 0; --i) {
      if (!prefix.empty() && prefix.back() == src[i]) {
        temp.push(prefix.back());
        prefix.pop_back();
      } else {
        while (!temp.empty()) {
          prefix.emplace_back(temp.top());
          temp.pop();
        }
      }
    }
  }

  for (auto &c : prefix) {
    cout << c;
  }
  cout << "\n";

  return 0;
}