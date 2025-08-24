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
#define FOR(i, a, A) for (ll i = a; i < A; ++i)
#define IFOR(i, a, A) for (ll i = a; i >= A; --i)

cll N = 1e5, M = 5e3, Inf = 1e9;
ll n, m, segs[2][N * 10] = {};

void add(ll node, ll st, ll en, ll idx, ll num) {
  if (idx < st || idx > en) {
    return;
  } else if (st == en) {
    segs[0][node] = segs[1][node] = num;
    return;
  }

  ll mid = (st + en) / 2;
  if (idx <= mid) {
    add(node * 2, st, mid, idx, num);
  } else {
    add(node * 2 + 1, mid + 1, en, idx, num);
  }

  segs[0][node] = min(segs[0][node * 2], segs[0][node * 2 + 1]),
  segs[1][node] = max(segs[1][node * 2], segs[1][node * 2 + 1]);
}

// value 보다 작거나 같은 것들의 개수
ll query(ll node, ll st, ll en, ll left, ll right, ll value) {
  if (right < st || left > en) {
    return 0;
  }

  ll minV = segs[0][node], maxV = segs[1][node], mid = (st + en) / 2;
  // cout << value << " " << st << "~" << en << " " << minV << "/" << maxV <<
  // "\n";
  if (minV > value) {
    return 0;
  }

  if (maxV <= value) {
    return min(right, en) - max(left, st) + 1;
  } else {
    return query(node * 2, st, mid, left, right, value) +
           query(node * 2 + 1, mid + 1, en, left, right, value);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  FOR(i, 0, n) {
    ll num;
    cin >> num;
    add(1, 0, n - 1, i, num);
  }

  FOR(q, 0, m) {
    ll i, j, k, st = 0, en = Inf, mid, ans, result;
    cin >> i >> j >> k;
    --i, --j;

    while (st <= en) {
      mid = (st + en) / 2, result = query(1, 0, n - 1, i, j, mid);
      // cout << st << "/" << en << " " << result << "\n";
      if (result < k) {
        st = mid + 1;
      } else {
        ans = mid, en = mid - 1;
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
