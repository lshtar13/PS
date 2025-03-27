#include <algorithm>
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

cll N = 2e5, C = N, S = 2000;
ll n;
vll colors, sizes, sums, colorSize[N + 1], colorSum[N + 1];
vpll inputs;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (ll i = 0, color, size; i < n; ++i) {
    cin >> color >> size;
    colors.push_back(color);

    sizes.push_back(size);
    sums.push_back(size);

    colorSize[color].push_back(sizes[i]);
    colorSum[color].push_back(sizes[i]);

    inputs.push_back({color, size});
  }

  sort(sizes.begin(), sizes.end());
  sort(sums.begin(), sums.end());
  for (ll i = 1; i < n; ++i) {
    sums[i] += sums[i - 1];
  }

  sort(colors.begin(), colors.end());
  colors.erase(unique(colors.begin(), colors.end()), colors.end());

  for (auto &c : colors) {
    sort(colorSize[c].begin(), colorSize[c].end());
    sort(colorSum[c].begin(), colorSum[c].end());
    for (ll i = 1; i < colorSum[c].size(); ++i) {
      colorSum[c][i] += colorSum[c][i - 1];
    }
  }

  ll color, size, pos0, pos1;
  for (auto &p : inputs) {
    tie(color, size) = p;
    pos0 = lower_bound(sizes.begin(), sizes.end(), size) - sizes.begin();
    pos1 = lower_bound(colorSize[color].begin(), colorSize[color].end(), size) -
           colorSize[color].begin();
    cout << sums[pos0] - colorSum[color][pos1] << "\n";
  }

  return 0;
}