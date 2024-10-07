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

cll N = 2000;
ll n, v[N] = {}, dp[N][N] = {{}};

ll search(ll st, ll en)
{
    if (st > en)
    {
        return 0;
    }
    else if (dp[st][en] != -1)
    {
        return dp[st][en];
    }

    ll k = n - en + st;
    dp[st][en] = search(st + 1, en) + k * v[st];
    dp[st][en] = max(dp[st][en], search(st, en - 1) + k * v[en]);

    return dp[st][en];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    cout << search(0, n - 1) << "\n";

    return 0;
}