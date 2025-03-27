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

// binary search(parametic)

cll L = 1e9, K = 1e4, C = 1e4;
ll l, k, c, pts[K + 2] = {};

bool termCheck(ll term) {
  ll nCut = 0, prv = l;
  for (ll pt = k; pt >= 0; --pt) {
    if (prv - pts[pt] > term) {
      return false;
    } else if (pt > 0 && prv - pts[pt - 1] > term) {
      prv = pts[pt], ++nCut;
    }
  }

  return nCut <= c;
}

bool firstPtCheck(ll fpt, ll term) {
  if (pts[fpt] > term) {
    return false;
  }

  ll nCut = 1;
  for (ll prv = pts[fpt], pt = fpt + 1; pt <= k; ++pt) {
    if (pts[pt] - prv > term) {
      return false;
    } else if (pts[pt + 1] - prv > term) {
      prv = pts[pt], ++nCut;
    }
  }

  return nCut <= c;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> l >> k >> c;
  for (ll pt = 1; pt <= k; ++pt) {
    cin >> pts[pt];
  }
  pts[k + 1] = l;
  sort(pts, pts + k + 2);

  ll st = 1, en = L, term, firstPt;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if (termCheck(mid)) {
      term = mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  st = 1, en = k;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if (firstPtCheck(mid, term)) {
      firstPt = mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  cout << term << " " << pts[firstPt] << " " << firstPt << "\n";

  return 0;
}