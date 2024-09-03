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

cll MAX_NUM = 5 * 1e5, MAX_SUM = MAX_NUM;
ll n, maxSum, dp[MAX_SUM + 1][51] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0][0] = 1, maxSum = 0;
    cin >> n;
    for (ll num, i = 0; i < n; ++i)
    {
        cin >> num;
        for (ll sum, _sum = maxSum; _sum >= 0; --_sum)
        {
            if (!dp[_sum][0])
            {
                continue;
            }
            sum = num + _sum, maxSum = max(maxSum, sum);
            for (ll bitMsk, idx = 1; idx <= dp[_sum][0]; ++idx)
            {
                dp[sum][++dp[sum][0]] = dp[_sum][idx] | (1 << i);
            }
        }
    }

    ll result = -1;
    for (ll s = 0; s <= maxSum; ++s)
    {
        if (dp[s][0] < 2)
        {
            continue;
        }

        // cout << s << " : ";
        for (ll i = 1; i < dp[s][0]; ++i)
        {
            for (ll l = i + 1; l <= dp[s][0]; ++l)
            {
                // cout << (dp[s][i] & dp[s][l]) << " ";
                if (!(dp[s][i] & dp[s][l]))
                {
                    result = s;
                    break;
                }
            }
        }
        // cout << "\n";
    }
    cout << result << "\n";

    return 0;
}