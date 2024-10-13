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
typedef vector<vll> vvll;

cll N = 100, M = 50, INF = 1e7;
ll n, m, preSum[N + 1] = {}, dp[N + 1][M] = {{{}}};

ll search(ll i, ll k)
{
    if (k <= 0)
    {
        return 0;
    }
    else if (i >= n)
    {
        return -INF;
    }
    else if (dp[i][k] != INF)
    {
        return dp[i][k];
    }

    dp[i][k] = -INF;
    dp[i][k] = max(dp[i][k], search(i + 1, k));
    for (ll l = i + 1; l <= n; ++l)
    {
        dp[i][k] = max(dp[i][k], preSum[l] - preSum[i] + search(l + 1, k - 1));
    }

    return dp[i][k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i <= n; ++i)
    {
        for (ll k = 0; k <= m; ++k)
        {
            dp[i][k] = INF;
        }
    }
    for (ll i = 1; i <= n; ++i)
    {
        cin >> preSum[i];
        preSum[i] += preSum[i - 1];
    }

    cout << search(0, m) << "\n";

    return 0;
}