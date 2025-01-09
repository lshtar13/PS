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

cll N = 100, M = 1e7, COST = 100;
ll n, m, memories[N + 1] = {}, costs[N + 1] = {}, dp[101][10001] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> memories[i];
    }
    for (ll i = 1; i <= n; ++i)
    {
        cin >> costs[i];
    }
    dp[0][0] = 0;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll c = 0; c < 10001; ++c)
        {
            dp[i][c] = dp[i - 1][c];
            if (c < costs[i] || dp[i - 1][c - costs[i]] == -1)
            {
                continue;
            }

            dp[i][c] = max(dp[i][c], dp[i - 1][c - costs[i]] + memories[i]);
        }
    }

    for (ll c = 0; c <= 10001; ++c)
    {
        if (dp[n][c] >= m)
        {
            cout << c << "\n";
            break;
        }
    }

    return 0;
}