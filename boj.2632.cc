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

cll S = 2e6, M = 1e3, N = 1e3;
ll s, npieces[2], pieces[2][N] = {{}}, sorts[2][S] = {{}};
bool checked[2][N][N] = {};

void check(ll i, ll st, ll en, ll sum) {
  if (checked[i][st][en]) {
    return;
  }
  ++sorts[i][sum], checked[i][st][en] = true;
  if (st != en) {
    check(i, (st + 1) % npieces[i], en, sum - pieces[i][st]);
    check(i, st, (en - 1 + npieces[i]) % npieces[i], sum - pieces[i][en]);
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s >> npieces[0] >> npieces[1];
  for (ll i = 0; i < 2; ++i) {
    ll sum = 0;
    for (ll piece = 0; piece < npieces[i]; ++piece) {
      cin >> pieces[i][piece];
      sum += pieces[i][piece];
    }

    for (ll st = 0; st < npieces[i]; ++st) {
      ll en = (st - 1 + npieces[i]) % npieces[i];
      check(i, st, en, sum);
    }
    sorts[i][0] = 1, sorts[i][sum] = 1;
  }

  ll result = 0;
  for (ll left = 0; left <= s; ++left) {
    ll right = s - left;
    result += sorts[0][left] * sorts[1][right];
  }

  cout << result << '\n';

  return 0;
}