#include <bits/stdc++.h>
#include <deque>

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

cll N = 1000, P = 1e5;
const pll Inf(P, P);
ll n, start;
pll prison, points[N + 2];
bool isIncluded[N + 2] = {};

inline ll ccw(pll cord0, pll cord1, pll cord2) {
  return cord0.first * cord1.second + cord1.first * cord2.second +
         cord2.first * cord0.second - cord1.first * cord0.second -
         cord2.first * cord1.second - cord0.first * cord2.second;
}

inline bool cmp0(ll a, ll b) {
  if (points[a].second == points[b].second) {
    return points[a].first < points[b].first;
  }
  return points[a].second < points[b].second;
}

inline bool cmp1(ll a, ll b) {
  return ccw(points[start], points[a], points[b]) >= 0;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> prison.first >> prison.second;
  FOR(i, n) { cin >> points[i].first >> points[i].second; }
  points[n] = prison, points[N + 1] = Inf;

  ll result = 0;
  while (true) {
    deque<ll> candidates, ans;
    FOR(i, n + 1) {
      if (!isIncluded[i]) {
        candidates.emplace_back(i);
      }
    }

    if (candidates.size() < 4) {
      goto End;
    }

    sort(candidates.begin(), candidates.end(), cmp0);
    start = candidates[0];
    sort(candidates.begin() + 1, candidates.end(), cmp1);

    isIncluded[candidates[0]] = true;
    ans.emplace_back(candidates[0]);
    candidates.pop_front();
    isIncluded[candidates[0]] = true;
    ans.emplace_back(candidates[0]);
    candidates.pop_front();
    for (auto &idx : candidates) {
      while (ans.size() >= 2 &&
             ccw(points[ans[ans.size() - 2]], points[ans[ans.size() - 1]],
                 points[idx]) <= 0) {
        isIncluded[ans.back()] = false;
        ans.pop_back();
      }
      isIncluded[idx] = true;
      ans.emplace_back(idx);
    }

    if (isIncluded[n]) {
      goto End;
    }

    ++result;
  }

End:
  cout << result << "\n";

  return 0;
}