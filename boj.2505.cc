#include <bits/stdc++.h>
#include <cwchar>

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

cll N = 1e4;
ll n, st, en, nums[N] = {};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0; i < n; ++i) {
    cin >> nums[i];
  }

  // lis?

  for (st = 0; st < n && nums[st] == st + 1; ++st) {
  }

  for (en = n - 1; en >= 0 && nums[en] == en + 1; --en) {
  }

  if (st == n) {
    cout << 1 << " " << n << "\n";
    cout << 1 << " " << n << "\n";
    return 0;
  }

  vll poles = {st};
  for (ll i = st + 1, g0, g1; i < en; ++i) {
    g0 = nums[i] - nums[i - 1], g1 = nums[i + 1] - nums[i];
    if (g0 != g1) {
      poles.emplace_back(++i);
    }
  }
  poles.emplace_back(en);

  if (poles.size() == 4) {
    cout << poles[0] + 1 << " " << poles[2] << "\n";
    cout << poles[1] << " " << poles[3] + 1 << "\n";
  } else if (poles.size() == 3) {
    if(nums[poles[0]]){}
  }

  for (auto &pole : poles) {
    cout << pole << " ";
  }
  cout << "\n";

  /*
        1 2 3 4
3 2 1 4
3 4 2 1
*/

  return 0;
}