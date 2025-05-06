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

cll A = 62, W = 5e4, S = 5e5;
ll pi[W] = {}, idxs[256] = {}, nalpha;
char alpha[A] = {};

void getPi(const string &str) {
  memset(pi, 0, sizeof(pi));
  for (ll i = 1, prv; i < str.length(); ++i) {
    prv = pi[i - 1];
    while (prv && str[i] == str[prv]) {
      prv = pi[prv - 1];
    }

    if (str[i] == str[prv]) {
      pi[i] = prv + 1;
    }
  }
}

ll comp(const string &tgt, const string &src, cll n) {
  ll result = 0;
  for (ll pt = 0, i = 0; pt < src.length();) {
    char c = alpha[(idxs[tgt[i]] + n) % nalpha];
    if (c == src[pt]) {
      ++i, ++pt;
    } else if (i) {
      i = pi[i - 1];
    } else {
      ++pt;
    }

    if (i == tgt.length()) {
      ++result, i = pi[tgt.length() - 1];
    }
  }

  return result;
}

string solve() {
  string stra, strw, strs;
  cin >> stra >> strw >> strs;

  nalpha = stra.length();
  for (ll i = 0; i < stra.length(); ++i) {
    idxs[stra[i]] = i;
    alpha[i] = stra[i];
  }

  vll results;
  getPi(strw);
  for (ll n = 0; n < stra.length(); ++n) {
    if (comp(strw, strs, n) == 1) {
      results.push_back(n);
    }
  }
  sort(results.begin(), results.end());

  string result;
  if (results.size() == 0) {
    result = "no solution";
  } else if (results.size() == 1) {
    result = "unique: ";
  } else {
    result = "ambiguous: ";
  }

  for (auto &num : results) {
    result += to_string(num);
    result += " ";
  }

  return result;
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