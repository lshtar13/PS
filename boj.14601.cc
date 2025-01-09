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

/*
0 1
2 3
*/

cll K = 256;
ll d, k, x, y, mat[K][K] = {}, id = 0;

void fill0(ll dimension, ll st0, ll st1, ll quad) {
  ll en0 = st0 + pow(2, dimension), en1 = st1 + pow(2, dimension),
     mean0 = (st0 + en0) / 2, mean1 = (st1 + en1) / 2, reserve;
  ll pt0_0 = st0, pt0_1 = st1, pt1_0 = st0, pt1_1 = mean1, pt2_0 = mean0,
     pt2_1 = st1, pt3_0 = mean0, pt3_1 = mean1,
     pt0 = st0 + pow(2, dimension - 2), pt1 = st1 + pow(2, dimension - 2);

//   cout << dimension << " " << st0 << " " << st1 << " " << quad << "\n";

  if (dimension == 1) {
    reserve = mat[st0 + quad / 2][st1 + quad % 2];
    mat[st0][st1] = mat[st0][en1 - 1] = mat[en0 - 1][st1] =
        mat[en0 - 1][en1 - 1] = ++id;
    mat[st0 + quad / 2][st1 + quad % 2] = reserve;
    return;
  }

  switch (quad) {
  case 0:
    fill0(dimension - 1, pt0, pt1, 0);
    fill0(dimension - 1, pt1_0, pt1_1, 2);
    fill0(dimension - 1, pt2_0, pt2_1, 1);
    fill0(dimension - 1, pt3_0, pt3_1, 0);
    return;
  case 1:
    fill0(dimension - 1, pt0, pt1, 1);
    fill0(dimension - 1, pt0_0, pt0_1, 3);
    fill0(dimension - 1, pt2_0, pt2_1, 1);
    fill0(dimension - 1, pt3_0, pt3_1, 0);
    return;
  case 2:
    fill0(dimension - 1, pt0, pt1, 2);
    fill0(dimension - 1, pt0_0, pt0_1, 3);
    fill0(dimension - 1, pt1_0, pt1_1, 2);
    fill0(dimension - 1, pt3_0, pt3_1, 0);
    return;
  default:
    fill0(dimension - 1, pt0, pt1, 3);
    fill0(dimension - 1, pt0_0, pt0_1, 3);
    fill0(dimension - 1, pt1_0, pt1_1, 2);
    fill0(dimension - 1, pt2_0, pt2_1, 1);
    return;
  }
}

void fill1(ll dimension, ll st0, ll st1) {
  ll en0 = st0 + pow(2, dimension), en1 = st1 + pow(2, dimension),
     mean0 = (st0 + en0) / 2, mean1 = (st1 + en1) / 2;

  if (!dimension) {
    mat[st0][st1] = -1;
    return;
  }

  if (x < mean0 && y < mean1) {
    fill1(dimension - 1, st0, st1);
    fill0(dimension, st0, st1, 0);
  } else if (x < mean0 && y >= mean1) {
    fill1(dimension - 1, st0, mean1);
    fill0(dimension, st0, st1, 1);
  } else if (x >= mean0 && y < mean1) {
    fill1(dimension - 1, mean0, st1);
    fill0(dimension, st0, st1, 2);
  } else {
    fill1(dimension - 1, mean0, mean1);
    fill0(dimension, st0, st1, 3);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> k >> x >> y;
  d = pow(2, k);
  y = d - y, --x;
  swap(x, y);
  fill1(k, 0, 0);

//   cout << "-----------\n";

  for (ll i = 0; i < d; ++i) {
    for (ll l = 0; l < d; ++l) {
      cout << mat[i][l] << " ";
    }
    cout << "\n";
  }

  return 0;
}