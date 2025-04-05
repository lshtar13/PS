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

cll N = 1e6, M = 1e6;
ll n, m, range, intensities[N] = {};
deque<ll> d;

void push(ll idx) {
  while (!d.empty()) {
    if (intensities[d.back()] > intensities[idx]) {
      break;
    } else {
      d.pop_back();
    }
  }
  d.push_back(idx);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (ll i = 0; i < n; ++i) {
    cin >> intensities[i];
  }
  range = 2 * m - 2;

  for (ll i = 0; i < range; ++i) {
    push(i);
  }

  for (ll i = 0; i + range < n; ++i) {
    push(i + range);
    while (d.front() < i) {
      d.pop_front();
    }

    cout << intensities[d.front()] << " ";
  }
  cout << "\n";

  return 0;
}