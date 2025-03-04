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

cll N = 1e5, L = 1e5;
ll n, heights[N] = {}, avail[N][2] = {{}}, near[N][2] = {{}};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> heights[i];
  }

  stack<pll> s0;
  for (ll i = n - 1; i >= 0; --i) {
    while (!s0.empty()) {
      if (s0.top().first <= heights[i]) {
        s0.pop();
      } else {
        break;
      }
    }

    avail[i][0] = s0.size();
    near[i][0] = s0.empty() ? -1 : s0.top().second;

    s0.push({heights[i], i});
  }

  stack<pll> s1;
  for (ll i = 0; i < n; ++i) {
    while (!s1.empty()) {
      if (s1.top().first <= heights[i]) {
        s1.pop();
      } else {
        break;
      }
    }

    avail[i][1] = s1.size();
    near[i][1] = s1.empty() ? -1 : s1.top().second;
    s1.push({heights[i], i});
  }

  for (ll i = 0, navail; i < n; ++i) {
    navail = avail[i][0] + avail[i][1];
    cout << navail << " ";
    if (near[i][0] != -1 && near[i][1] != -1) {
      ll dist0 = near[i][0] - i, dist1 = i - near[i][1];
      if (dist1 <= dist0) {
        cout << near[i][1] + 1;
      } else {
        cout << near[i][0] + 1;
      }
    } else if (near[i][0] != -1) {
      cout << near[i][0] + 1;
    } else if (near[i][1] != -1) {
      cout << near[i][1] + 1;
    }
    cout << "\n";
  }

  return 0;
}