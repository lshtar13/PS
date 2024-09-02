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

cll MAX_N = 100, MAX_DP = 1e9;
ll n, dp[MAX_N + 1][10][1024] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 1; i <= 9; ++i)
    {
        dp[1][i][1 << i] = 1;
    }

    for (ll len = 1; len < n; ++len)
    {
        for (ll tail = 0; tail < 10; ++tail)
        {
            for (ll _status, status = 0; status < 1024; ++status)
            {
                if (tail > 0)
                {
                    _status = status | (1 << tail - 1);
                    dp[len + 1][tail - 1][_status] += dp[len][tail][status];
                    dp[len + 1][tail - 1][_status] %= MAX_DP;
                }

                if (tail < 9)
                {
                    _status = status | (1 << tail + 1);
                    dp[len + 1][tail + 1][_status] += dp[len][tail][status];
                    dp[len + 1][tail + 1][_status] %= MAX_DP;
                }
            }
        }
    }

    ll result = 0;
    for (ll tail = 0; tail < 10; ++tail)
    {
        result = (result + dp[n][tail][1023]) % MAX_DP;
    }

    cout << result << "\n";

    return 0;
}