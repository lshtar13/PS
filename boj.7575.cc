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

cll N = 100, K = 1000, M = 1000;
ll n, k;
vll programs[N];
ll results[N][M] = {{}};
vll tgts[2][M], pis[2][M];

void addPi(vll &tgt, vll &pi, ll num) {
  ll _pi = pi.back();
  while (_pi > 0 && num != tgt[_pi]) {
    _pi = pi[_pi - 1];
  }

  pi.emplace_back(num == tgt[_pi] ? _pi + 1 : 0);
}

bool kmp(vll &src, vll &tgt) {
  vll pi = {0};
  for (auto &t : tgt) {
    addPi(tgt, pi, t);
  }

  ll a = 0, b = 0;
  while (a < src.size()) {
    if (src[a] == tgt[b]) {
      ++a, ++b;
    } else if (!b) {
      ++a;
    } else {
      b = pi[b - 1];
    }

    if (b == tgt.size()) {
      return true;
    }
  }

END:
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  for (ll m, i = 0; i < n; ++i) {
    cin >> m;
    programs[i].resize(m);
    for (ll l = 0; l < m; ++l) {
      cin >> programs[i][l];
    }
  }

  vll &src = programs[0];
  for (ll st = 0; st < src.size(); ++st) {
    vll tgt = vll(src.begin() + st, src.begin() + st + k);
    bool result = true;
    for (ll p = 1; result && p < n; ++p) {
      bool _result = false;
      _result |= kmp(programs[p], tgt);
      reverse(tgt.begin(), tgt.end());
      _result |= kmp(programs[p], tgt);
      result &= _result;
    }

    if (result) {
      cout << "YES" << "\n";
      goto END;
    }
  }

  cout << "NO\n";
END:

  return 0;
}