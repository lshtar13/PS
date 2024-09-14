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

cll MAX_N = 50;
ll n, child[MAX_N][MAX_N] = {}, dp[MAX_N] = {};

ll search(ll k)
{
    if (dp[k] >= 0)
    {
        return dp[k];
    }

    dp[k] = 0;
    pqll pq;
    for (ll i = 0; i < n; ++i)
    {
        if (child[k][i])
        {
            pq.push(search(i));
        }
    }

    for (ll i = 1; !pq.empty(); ++i)
    {
        dp[k] = max(dp[k], i + pq.top());
        pq.pop();
    }

    return dp[k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll a, i = 0; i < n; ++i)
    {
        cin >> a;
        if (a >= 0)
        {
            child[a][i] = 1;
        }
        dp[i] = -1;
    }

    cout << search(0);

    return 0;
}