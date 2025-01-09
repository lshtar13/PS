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

cll N = 5, directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
ll nCord, result = 50;
vpll cords;

bool isValidCord(ll i, ll l) { return i >= 0 && i < 5 && l >= 0 && l < 5; }

bool isValidStatus(ll st, ll tgts[][N]) {
  ll nConnected = 1;
  qll q;
  q.push(st);
  tgts[q.front() / N][q.front() % N] = 0;
  while (!q.empty()) {
    ll i = q.front() / N, l = q.front() % N;
    q.pop();

    for (auto &d : directions) {
      ll _i = i + d[0], _l = l + d[1];
      pll next(_i, _l);
      if (!isValidCord(_i, _l) || !tgts[_i][_l]) {
        continue;
      }

      ++nConnected;
      q.push(_i * N + _l);
      tgts[_i][_l] = 0;
    }
  }

  return nConnected == nCord;
}

ll calc(ll idx, ll tgt) {
  ll i = cords[idx].first, l = cords[idx].second;
  ll _i = tgt / N, _l = tgt % N;

  return abs(i - _i) + abs(l - _l);
}

void search(vll &v, ll status) {
  if (v.size() == nCord) {
    ll tgts[N][N] = {{}}, dist = 0;
    for (auto &p : v) {
      tgts[p / N][p % N] = 1;
    }
    if (!isValidStatus(v.front(), tgts)) {
      return;
    }

    ll i = 0;
    for (auto &p : v) {
      dist += calc(i++, p);
    }
    result = min(result, dist);
    return;
  }

  for (ll i = 0; i < N * N;) {
    if (status & (1 << i)) {
      goto END;
    }
    status &= (1 << i);
    v.emplace_back(i);
    search(v, status);
    v.pop_back();
    status ^= (1 << i);
  END:
    ++i;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (ll i = 0; i < 5; ++i) {
    for (ll l = 0; l < 5; ++l) {
      char c;
      cin >> c;
      if (c == '*') {
        ++nCord;
        cords.emplace_back(make_pair(i, l));
      }
    }
    cin.ignore();
  }

  vll status;
  search(status, 0);
  cout << result << "\n";

  return 0;
}