#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <utility>

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

typedef pair<int, int> pii;
cll N = 5e6, L = 5e6;
ll n, l;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  //  cin >> n >> l;
  //  priority_queue<pii, vector<pii>, greater<pii>> pq;
  //  FOR(i, 0, n) {
  //    ll num, bound = max(ll(0), i - l + 1);
  //    cin >> num;
  //    pq.push({num, i});
  //    while (pq.top().second < bound) {
  //      pq.pop();
  //    }

  //    cout << pq.top().first << " ";
  //  }
  //  cout << "\n";

  deque<pii> dq;
  cin >> n >> l;
  FOR(i, 0, n) {
    ll num, bound = max(ll(0), i - l + 1);
    cin >> num;
    while (!dq.empty() && dq.back().first > num) {
      dq.pop_back();
    }

    dq.push_back({num, i});
    while (dq.front().second < bound) {
      dq.pop_front();
    }

    cout << dq.front().first << " ";
  }
  cout << "\n";

  return 0;
}