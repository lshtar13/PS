#include <bits/stdc++.h>
#include <climits>
#include <cstdint>

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

cll A = 1, B = 50, C = 50 * 50, MAX_REST = 50 * 50 * 50;
ll records[3] = {}, weights[3] = {A, B, C}, nemployees = 0;
bool dp[51][51][51][3][3] = {};
char employees[] = "ABC";

string search(ll prv0, ll prv1) {
  bool possible[3] = {true, prv0 != 1, prv0 != 2 && prv1 != 2};

  if (dp[records[0]][records[1]][records[2]][prv0][prv1]) {
    return "-1";
  } else if (nemployees == 0) {
    return "";
  }

  string next;
  for (ll e = 0; e < 3; ++e) {
    if (records[e] <= 0 || !possible[e]) {
      continue;
    }

    --nemployees;
    --records[e];
    next = search(e, prv0);
    if (next != "-1") {
      return string(1, e + 'A') + next;
    }
    ++records[e];
    ++nemployees;
  }

  dp[records[0]][records[1]][records[2]][prv0][prv1] = true;
  return "-1";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string employees;
  cin >> employees;
  for (auto &employee : employees) {
    ++records[employee - 'A'], ++nemployees;
  }

  cout << search(0, 0) << "\n";

  return 0;
}