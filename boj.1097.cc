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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 8, K = 20, Length = 20;
ll n, k;
string words[N];

bool check(string &word) {
  ll pi[N * Length] = {}, length = word.length();
  FOR(i, 1, length) {
    ll prv = pi[i - 1];
    while (prv && word[prv] != word[i]) {
      prv = pi[prv - 1];
    }

    if (word[prv] == word[i]) {
      pi[i] = prv + 1;
    } else {
      pi[i] = 0;
    }
  }

  string tgt = word + word;
  ll pos = 0, idx = 0, result = 0;
  while (pos < tgt.length() - 1) {
    if (tgt[pos] == word[idx]) {
      ++pos, ++idx;
    } else if (idx > 0) {
      idx = pi[idx - 1];
    } else {
      ++pos;
    }

    if (idx == length) {
      ++result;
      idx = pi[idx - 1];
    }
  }

  return result == k;
}

ll permute(ll level) {
  static string word;
  static bool selected[N] = {};
  if (level == n) {
    return check(word);
  }

  ll result = 0;
  FOR(i, 0, n) {
    if (selected[i]) {
      continue;
    }

    selected[i] = true;
    word += words[i];
    result += permute(level + 1);
    word.erase(word.end() - words[i].length(), word.end());
    selected[i] = false;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin.ignore();
  FOR(i, 0, n) { getline(cin, words[i]); }
  cin >> k;
  cout << permute(0) << "\n";

  return 0;
}