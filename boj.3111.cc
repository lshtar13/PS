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

cll Text = 3e5, Tgt = 25;
string tgt, rtgt, text;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, tgt);
  getline(cin, text);

  rtgt = tgt;
  reverse(rtgt.begin(), rtgt.end());

  string left, right;
  deque<char> dq;
  FOR(i, 0, text.length()) { dq.push_back(text[i]); }
  while (true) {
    while (true) {
      if (!dq.empty()) {
        left.push_back(dq.front());
        dq.pop_front();
      } else if (!right.empty()) {
        left.push_back(right.back());
        right.pop_back();
      } else {
        goto END;
      }

      if (tgt.length() <= left.length() &&
          left.substr(left.length() - tgt.length(), tgt.length()) == tgt) {
        FOR(i, 0, tgt.length()) { left.pop_back(); }
        break;
      }
    }

    while (true) {
      if (!dq.empty()) {
        right.push_back(dq.back());
        dq.pop_back();
      } else if (!left.empty()) {
        right.push_back(left.back());
        left.pop_back();
      } else {
        goto END;
      }

      if (tgt.length() <= right.length() &&
          right.substr(right.length() - tgt.length(), tgt.length()) == rtgt) {
        FOR(i, 0, tgt.length()) { right.pop_back(); }
        break;
      }
    }
  }

END:
  reverse(right.begin(), right.end());
  cout << left << right << "\n";

  return 0;
}