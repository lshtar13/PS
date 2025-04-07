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

cll N = 100, M = 500;
ll n, m, owner[N + 1] = {};
vll edges[N + 1];

bool find(ll student, bool visited[]) {
  for (auto &dst : edges[student]) {
    if (visited[dst]) {
      continue;
    }
    visited[dst] = true;

    if (!owner[dst] || find(owner[dst], visited)) {
      owner[dst] = student;
      return true;
    }
  }

  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll a, b, i = 0; i < m; ++i) {
    cin >> a >> b;
    edges[a].emplace_back(b);
  }

  ll result = 0;
  for (ll student = 1; student <= n; ++student) {
    bool visited[N + 1] = {};
    result += find(student, visited);
  }
  cout << result << "\n";

  return 0;
}