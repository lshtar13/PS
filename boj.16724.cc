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

cll N = 1000, M = 1000;
ll n, m, parents[N * M] = {};
char mat[N][M] = {};
bool isExist[N * M] = {};

ll find(ll node) {
  if (node == parents[node]) {
    return node;
  }

  return parents[node] = find(parents[node]);
}

void merge(ll child, ll parent) { parents[child] = find(parent); }

void gather(ll i, ll l) {
  ll cur = i * m + l, next;
  switch (mat[i][l]) {
  case 'U':
    next = (i - 1) * m + l;
    break;
  case 'D':
    next = (i + 1) * m + l;
    break;
  case 'L':
    next = i * m + l - 1;
    break;
  case 'R':
    next = i * m + l + 1;
    break;
  }

  merge(cur, next);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin.ignore();
    for (ll l = 0; l < m; ++l) {
      cin >> mat[i][l];
      parents[i * m + l] = i * m + l;
    }
  }

  ll result = 0;
  FOR2(i, l, n, m) { gather(i, l); }
  FOR2(i, l, n, m) {
    ll parent = find(i * m + l);
    if (!isExist[parent]) {
      ++result;
      isExist[parent] = true;
    }
  }

  cout << result << "\n";

  return 0;
}