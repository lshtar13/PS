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

cll N = 100, LEN = 10, NALPHA = 'z' - 'a';
ll n, nChar = 0, degree[NALPHA + 1] = {};
string words[N];
bool mat[NALPHA + 1][NALPHA + 1] = {{}}, present[NALPHA + 1] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> words[i];
  }

  for (auto &word : words) {
    for (auto c : word) {
      present[c - 'a'] = true;
    }
  }

  for (ll c = 0; c <= NALPHA; ++c) {
    nChar += present[c];
  }

  for (ll minLen, cPrv, cCur, l, i = 1; i < n; ++i) {
    string &prv = words[i - 1], &cur = words[i];
    minLen = min(prv.length(), cur.length());
    for (l = 0; l < minLen; ++l) {
      if (prv[l] != cur[l]) {
        break;
      }
    }

    if (l == minLen) {
      if (prv.length() > minLen) {
        cout << "!\n";
        return 0;
      }
      continue;
    }

    cPrv = prv[l] - 'a', cCur = cur[l] - 'a';
    if (!mat[cPrv][cCur]) {
      mat[cPrv][cCur] = true;
      ++degree[cCur];
    }
  }

  char result[NALPHA + 1] = {}, nresult = 0;

  qll q;
  for (ll i = 0; i <= NALPHA; ++i) {
    if (present[i] && !degree[i]) {
      q.push(i);
    }
  }
  bool isAmbiguous = false;
  while (!q.empty()) {
    if (q.size() > 1) {
      isAmbiguous = true;
    }

    ll alpha = q.front();
    q.pop();

    result[nresult++] = alpha + 'a';

    for (ll a = 0; a <= NALPHA; ++a) {
      if (mat[alpha][a] && !--degree[a]) {
        q.push(a);
      }
    }
  }

  if (nresult < nChar) {
    cout << "!\n";
  } else if (isAmbiguous) {
    cout << "?\n";
  } else {
    cout << result << "\n";
  }
  return 0;
}