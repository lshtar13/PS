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

cll N = 1e4, M = 1e4;
ll n, m, choices[M + 1], spares[N + 1];
bool visited[M + 1];

bool find(ll choice, ll student) {
  ll idx = abs(choice), sign = choice / idx, owner;
  visited[idx] = true;
  if (choices[idx]) {
    if ((choice < 0 && choices[idx] < 0) || (choice > 0 && choices[idx] > 0)) {
      return true;
    } else {
      owner = abs(choices[idx]);
      if (!visited[idx] && spares[owner] && find(spares[owner], owner)) {
        choices[idx] = sign * student;
        return true;
      } else {
        return false;
      }
    }
  } else {
    choices[idx] = sign * student;
    return true;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 이분매칭 ...
  cin >> n >> m;
  for (ll student = 1, x, y; student <= n; ++student) {
    cin >> x >> y;
    memset(visited, 0, sizeof(visited));
    if (find(x, student)) {
      spares[student] = y;
    } else if (find(y, student)) {
      spares[student] = 0;
    } else {
      cout << "OTL\n";
      goto END;
    }
  }
  cout << "^_^\n";

END:

  return 0;
}