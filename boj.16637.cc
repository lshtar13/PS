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
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)                                                       \
  for (ll a = 0; a < A; ++a)                                                   \
    for (ll b = 0; b < B; ++b)

cll N = 19;
ll n;
string form;
ll minFind(string &form, ll idx);
ll maxFind(string &form, ll idx);

ll minFind(string &form, ll idx) {
  ll num = form[idx] - '0', nextNum, _result, result;
  if (idx == 0) {
    return num;
  }

  switch (form[idx - 1]) {
  case '+':
    result = num + minFind(form, idx - 2);
    break;
  case '-':
    result = minFind(form, idx - 2) - num;
    break;
  case '*':
    result = num * maxFind(form, idx - 2);
    result = min(result, num * minFind(form, idx - 2));
    break;
  }

  if (idx < 4) {
    goto END;
  }

  nextNum = form[idx - 2] - '0';
  switch (form[idx - 1]) {
  case '+':
    _result = num + nextNum;
    break;
  case '-':
    _result = nextNum - num;
    break;
  case '*':
    _result = num * nextNum;
    break;
  }

  switch (form[idx - 3]) {
  case '+':
    result = min(result, _result + minFind(form, idx - 4));
    break;
  case '-':
    result = min(result, minFind(form, idx - 4) - _result);
    break;
  case '*':
    result = min(result, _result * minFind(form, idx - 4));
    result = min(result, _result * maxFind(form, idx - 4));
    break;
  }

END:
  return result;
}

ll maxFind(string &form, ll idx) {
  ll num = form[idx] - '0', nextNum, _result, result;
  if (idx == 0) {
    return num;
  }

  switch (form[idx - 1]) {
  case '+':
    result = num + maxFind(form, idx - 2);
    break;
  case '-':
    result = maxFind(form, idx - 2) - num;
    break;
  case '*':
    result = num * maxFind(form, idx - 2);
    result = max(result, num * minFind(form, idx - 2));
    break;
  }

  if (idx < 4) {
    goto END;
  }

  nextNum = form[idx - 2] - '0';
  switch (form[idx - 1]) {
  case '+':
    _result = num + nextNum;
    break;
  case '-':
    _result = nextNum - num;
    break;
  case '*':
    _result = num * nextNum;
    break;
  }

  switch (form[idx - 3]) {
  case '+':
    result = max(result, _result + maxFind(form, idx - 4));
    break;
  case '-':
    result = max(result, maxFind(form, idx - 4) - _result);
    break;
  case '*':
    result = max(result, _result * minFind(form, idx - 4));
    result = max(result, _result * maxFind(form, idx - 4));
    break;
  }

END:
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> form;

  ll result = maxFind(form, form.size() - 1);
  cout << result << "\n";

  return 0;
}