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

cll N = 75e3, X = 1e9, Y = 1e9;
ll n, segs[N * 15] = {}, ycords[N] = {};
pll cords[N];

ll update(ll node, ll st, ll en, ll num, ll amnt) {
  segs[node] += amnt;
  if (st == en) {
    return segs[node] - amnt;
  }

  ll mid = (st + en) / 2;
  if (num <= mid) {
    return update(node * 2, st, mid, num, amnt) + segs[node * 2 + 1];
  } else {
    return update(node * 2 + 1, mid + 1, en, num, amnt);
  }
}

bool comp(pll &a, pll &b) {
  if (a.first != b.first) {
    return a.first < b.first;
  } else {
    return a.second > b.second;
  }
}

ll solve() {
  map<ll, ll> indexs;
  cin >> n;
  FOR(i, n) {
    cin >> cords[i].first >> cords[i].second;
    indexs[cords[i].second] = 1;
  }

  ll idx = 0;
  for (auto &p : indexs) {
    indexs[p.first] = ++idx;
  }

  ll result = 0;
  sort(cords, cords + n, comp);
  memset(segs, 0, sizeof(segs));
  FOR(i, n) { result += update(1, 0, N, indexs[cords[i].second], 1); }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin >> t;
  while (t--) {
    cout << solve() << "\n";
  }

  return 0;
}