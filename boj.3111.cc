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
string tgt, src;
ll pi[A] = {}, checked[T + 1] = {-1};

void getPi() {
  for (ll prv, i = 1; i < tgt.size(); ++i) {
    prv = pi[i - 1];
    while (prv && tgt[prv] != tgt[i]) {
      prv = pi[prv - 1];
    }

    if (tgt[prv] == tgt[i]) {
      pi[i] = prv + 1;
    } else {
      pi[i] = 0;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> tgt >> src;
  getPi();
  src = "0" + src;

  string result;
  for (ll s = 1, t = 0, prv = 1; s < src.size();) {
    if (src[s] != tgt[t]) {
      t = pi[t];
    } else if (t == tgt.size() - 1) {
        
    } else {
      checked[s] = t;
      ++s, ++t;
    }
  }

  return 0;
}