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

cll N = 20, M = 20, P = 1000;
ll n, m, scores[8] = {};
bool mat[N][M] = {{}},
     blocks[8][2][4] = {{{true, true, true, true}, {}},
                        {{true}, {true, true, true}},
                        {{false, false, true}, {true, true, true}},
                        {{true, true}, {true, true}},
                        {{false, true, true}, {true, true}},
                        {{false, true}, {true, true, true}},
                        {{
                             true,
                             true,
                         },
                         {false, true, true}},
                        {{true}}};
pll sizes[8] = {{1, 4}, {2, 3}, {2, 3}, {2, 2}, {2, 3}, {2, 3}, {2, 3}, {1, 1}};

pll convert()

bool isValid(ll a, ll b, ll idx, ll direction) {

}

pll check() {
  pll result = {0, 0};
  FOR(a, 0, n) FOR(b, 0, m) FOR(i, 0, 8) FOR(d, 0, 4) {
    if (!isValid(a, b, i, d)) {
      continue;
    }

    mark(a, b, i, d);
    pll nresult = check();
    swap(nresult.first, nresult.second);
    nresult.first += scores[i];
    if (nresult.first > result.first) {
      result = nresult;
    } else if (nresult.first == result.first &&
               nresult.second < result.second) {
      result = nresult;
    }
  }

  return result;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  FOR(i, 0, 8) { cin >> scores[i]; }

  pll result = check();

  return 0;
}