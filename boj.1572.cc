#include <bits/stdc++.h>
#include <queue>

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

cll N = 25e4, K = 5e3;
ll n, k;
bool isLeft[N] = {};
pqpll pq0;
priority_queue<pll, vpll, greater<pll>> pq1;

ll push(ll num) {
  static ll idx = 0, nleft = 0, nright = 0;
  pq0.push({num, idx});
  isLeft[idx] = true;

  if (idx >= k) {
    if (isLeft[idx - k]) {
      ++nleft;
    } else {
      ++nright;
    }
  }

  while (pq1.empty() || pq0.top().first > pq1.top().first) {
    ll nnum = pq0.top().first, nidx = pq0.top().second;
    pq0.pop();
    if (nidx <= idx - k) {
      --nleft;
    } else {
      isLeft[nidx] = false;
      pq1.push({nnum, nidx});
    }
  }

  while (pq0.size() - nleft < pq1.size() - nright) {
    ll nnum = pq1.top().first, nidx = pq1.top().second;
    pq1.pop();

    if (nidx <= idx - k) {
      --nright;
    } else {
      isLeft[nidx] = true;
      pq0.push({nnum, nidx});
    }
  }

  while (pq0.size() - nleft > pq1.size() - nright + 1 ||
         pq0.top().second <= idx - k) {
    ll nnum = pq0.top().first, nidx = pq0.top().second;
    pq0.pop();

    if (nidx <= idx - k) {
      --nleft;
    } else {
      isLeft[nidx] = false;
      pq1.push({nnum, nidx});
    }
  }

  return ++idx >= k ? pq0.top().first : 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll result = 0;
  cin >> n >> k;
  FOR(i, 0, n) {
    ll num;
    cin >> num;
    result += push(num);
  }

  cout << result << "\n";

  return 0;
}