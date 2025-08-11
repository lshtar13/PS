#include <bits/stdc++.h>
#include <climits>

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

typedef tuple<ll, ll, ll> info_t;

cll N = 2e4;
ll n;
info_t infos[N];

ll count(ll bound) {
  ll result = 0;
  FOR(i, 0, n) {
    ll a, b, c;
    tie(a, b, c) = infos[i];

    if (bound < a) {
      break;
    }

    result += (min(bound, b) - a) / c + 1;
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  FOR(i, 0, n) {
    ll a, b, c;
    cin >> a >> b >> c;
    infos[i] = {a, b, c};
  }
  sort(infos, infos + n);

  ll st = 1, en = INT_MAX, ans, cnt;
  while (st <= en) {
    ll mid = (st + en) / 2, sum = count(mid);
    if (sum % 2) {
      ans = mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  cnt = count(ans) - count(ans - 1);
  if (!cnt) {
    cout << "NOTHING\n";
  } else {
    cout << ans << " " << cnt << "\n";
  }

  return 0;
}