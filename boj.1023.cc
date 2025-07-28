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

cll N = 50, K = 2 ^ 50 - 1, Normal = N + 1, Total = N + 2,
    normal2Abnormal[4] = {0, 0, 0, 2}, change[4] = {-2, 0, 0, 2},
    nchange[4][2] = {{0, 2}, {0, 0}, {1, 1}, {2, 0}};
ll n, k, dp[N + 1][N + 2] = {{}}, sums[N + 4][N + 1][4] = {{{}}};
bool Accessible2Normal[4] = {true, false, true, true};
string prefixs[4] = {"((", "()", ")(", "))"};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;

  dp[0][Normal] = 1;
  FOR(idx, 1, n + 1) FOR(prefix, 0, 4) {
    if (idx % 2) {
      continue;
    }

    ll prv = idx - 2;
    if (Accessible2Normal[prefix]) {
      dp[idx][normal2Abnormal[prefix]] += dp[prv][Normal],
          sums[Total][idx][prefix] += dp[prv][Normal],
          sums[normal2Abnormal[prefix]][idx][prefix] += dp[prv][Normal];
    } else {
      dp[idx][Normal] += dp[prv][Normal],
          sums[Total][idx][prefix] += dp[prv][Normal],
          sums[Normal][idx][prefix] += dp[prv][Normal];
    }

    dp[idx][0] += dp[prv][0], sums[Total][idx][prefix] += dp[prv][0],
        sums[0][idx][prefix] += dp[prv][0];

    FOR(lack, 1, n + 1) {
      if (lack % 2) {
        continue;
      }

      ll nlack = lack + change[prefix];
      if (!nlack) {
        dp[idx][Normal] += dp[prv][lack],
            sums[Total][idx][prefix] += dp[prv][lack],
            sums[Normal][idx][prefix] += dp[prv][lack];
      } else {
        dp[idx][nlack] += dp[prv][lack],
            sums[Total][idx][prefix] += dp[prv][lack],
            sums[nlack][idx][prefix] += dp[prv][lack];
      }
    }
  }

  string result;
  if (n % 2) {
    FOR(pos, 0, n) {
      result = ((k % 2) ? ")" : "(") + result;
      k /= 2;
    }
  } else {
    ll idx = n, total = (ll(1) << n) - dp[n][Normal], sidx = Normal, cnt = 0;
    if (k >= total) {
      result = "-1";
      goto END;
    }

    bool isAbnormal = false;
    while (idx > 0) {
      FOR(prefix, 0, 4) {
        ll sum = sums[Total][idx][prefix] - sums[sidx][idx][prefix];
        if (sum > k) {
          result = result + prefixs[prefix];
          if (!isAbnormal) {
            cnt -= nchange[prefix][0];
            if (cnt < 0) {
              isAbnormal = true, sidx = Total + 1;
            } else {
              cnt += nchange[prefix][1];
              sidx = cnt == 0 ? Normal : cnt;
            }
          }
          break;
        } else {
          k -= sum;
        }
      }

      idx -= 2;
    }
  }

END:
  cout << result << "\n";

  return 0;
}