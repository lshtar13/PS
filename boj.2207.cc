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
ll n, m, spares[N + 1];
bool visited[M + 1];
vll choices[M + 1];

bool find(ll choice, ll student) {
  ll idx = abs(choice), sign = choice / idx, owner;
  visited[idx] = true;
  if (!choices[idx].empty()) {
    ll prvSign = choices[idx].front() / abs(choices[idx].front());
    if (prvSign == sign) {
      return true;
    } else {
      for (auto &_owner : choices[idx]) {
        ll owner = _owner * prvSign;
        if (!visited[idx] && spares[owner] && find(spares[owner], owner)) {
        } else {
          return false;
        }
      }
      choices[idx].clear();
      choices[idx].emplace_back(sign * student);
      return true;
    }
  } else {
    choices[idx].emplace_back(sign * student);
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