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

cll NBIT = 55, DV = 1e16, ONE = 1;
ll a, b;

ll find(ll bit) {
  ll ground = (ONE << bit);
  if (ground > b) {
    return 0;
  }

  ll st = 0, en = DV, minV, maxV;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if ((ground | mid) >= a) {
      minV = ground | mid, en = mid - 1;
    } else {
      st = mid + 1;
    }
  }

  st = 0, en = DV;
  while (st <= en) {
    ll mid = (st + en) / 2;
    if ((ground | mid) <= b) {
      maxV = ground | mid, st = mid + 1;
    } else {
      en = mid - 1;
    }
  }

  ll lwMsk = (ONE << (bit + 1)) - 1, upMsk = ~lwMsk, result = 1;

  result += (lwMsk & maxV) - (lwMsk & minV);
  result += ((upMsk & maxV) >> 1) - ((upMsk & minV) >> 1);

//   cout << bit << ":" << (bitset<10>(minV)) << " " << (bitset<10>(maxV)) << " / "
//        << result << "\n";
  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;

  ll result = 0;
  for (ll bit = 0; bit < NBIT; ++bit) {
    result += find(bit);
  }

  cout << result << "\n";

  return 0;
}