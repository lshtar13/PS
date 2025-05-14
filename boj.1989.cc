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

cll N = 1e5;
ll n, sums[N + 1] = {};
set<ll> minIdxs[2];
pll infos[N];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0, num; i < n; ++i) {
    cin >> num;
    infos[i] = {num, i};
    sums[i + 1] = sums[i] + num;
  }
  sort(infos, infos + n);

  ll result = -1, st, en;
  qll buf;
  minIdxs[0].insert(1);
  minIdxs[1].insert(-1);
  minIdxs[0].insert(-n);
  minIdxs[1].insert(n);
  for (ll i = 0, num, idx; i < n; ++i) {
    tie(num, idx) = infos[i];

    ll nst = -(*minIdxs[0].upper_bound(-idx)) + 1,
       nen = *minIdxs[1].upper_bound(idx) - 1,
       nresult = (sums[nen + 1] - sums[nst]) * num;
    // cout << nst << " " << nen << " " << num << "/" << nresult << "\n";
    if (result < nresult) {
      st = nst, en = nen, result = nresult;
    }

    minIdxs[0].insert(-idx);
    minIdxs[1].insert(idx);
  }

  cout << result << "\n";
  cout << st + 1 << " " << en + 1 << "\n";

  return 0;
}