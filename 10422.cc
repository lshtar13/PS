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

cll MAX_DP = 1e9 + 7;
ll t, l, dp[5001] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    dp[0] = 1, dp[1] = 0, dp[2] = 1;
    for (ll i = 3; i <= 5000; ++i)
    {
        dp[i] = 0;
        if (i % 2)
        {
            continue;
        }

        for (ll l = i - 2; l >= 0; --l)
        {
            dp[i] += dp[l] * dp[i - l - 2],
                dp[i] %= MAX_DP;
        }
    }

    cin >> t;
    while (t--)
    {
        cin >> l;
        cout << dp[l] << "\n";
    }

    return 0;
}