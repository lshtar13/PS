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

cll N = 1000, M = 1000, INF = 1e9 + 1;
ll n, m, male[N] = {}, female[M] = {}, dp[N + 1][M + 1] = {{}};

ll search(ll i, ll l)
{
    if (i < 0 || l < 0)
    {
        return 0;
    }
    else if (dp[i][l] != -1)
    {
        return dp[i][l];
    }

    dp[i][l] = INF;
    dp[i][l] = min(dp[i][l], search(i - 1, l - 1) + abs(male[i] - female[l]));
    ll _i = i, _l = l, &dom = _i > _l ? _i : _l;
    while (_i != _l)
    {
        --dom;
        dp[i][l] = min(dp[i][l], search(_i, _l));
    }

    return dp[i][l];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
    {
        cin >> male[i];
    }
    for (ll i = 0; i < m; ++i)
    {
        cin >> female[i];
    }
    sort(male, male + n);
    sort(female, female + m);

    cout << search(n - 1, m - 1) << "\n";

    return 0;
}