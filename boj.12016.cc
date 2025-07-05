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
#define FOR(a, A) for (ll a = 0; a < A; ++a)

cll N = 1e5, Time = 1e9;
ll n, segs[N * 10] = {}, results[N] = {};
pll durs[N];

ll query(ll node, ll st, ll en, ll idx) {
  if (idx < st) {
    return 0;
  } else if (en <= idx) {
    return segs[node];
  }

  ll mid = (st + en) / 2;
  return query(node * 2, st, mid, idx) + query(node * 2 + 1, mid + 1, en, idx);
}

void add(ll node, ll st, ll en, ll idx) {
  if (idx < st || idx > en) {
    return;
  }

  ++segs[node];
  ll mid = (st + en) / 2;
  if (st < en && idx <= mid) {
    add(node * 2, st, mid, idx);
  } else if (idx > mid) {
    add(node * 2 + 1, mid + 1, en, idx);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, n) {
    cin >> durs[i].first;
    durs[i].second = i;
  }
  sort(durs, durs + n);

  FOR(i, n) {
    static ll cur = 1, sum = 0, offset = 0, idx, dur;
    tie(dur, idx) = durs[i];

    if (cur != dur) {
      sum += (dur - cur - 1) * (n - i) + n - i + offset, cur = dur, offset = 0;
    }

    results[idx] = idx + 1 - query(1, 0, n - 1, idx) + sum + offset;
    add(1, 0, n - 1, idx);
    ++offset;
  }

  FOR(i, n) { cout << results[i] << "\n"; }

  return 0;
}