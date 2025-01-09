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

ll n, dp[16] = {}, t[15] = {}, p[15] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> t[i] >> p[i];
    }

    ll result = 0;
    for (ll _t, _p, d = n - 1; d >= 0; --d)
    {
        _t = t[d], _p = p[d];
        for (ll _d = d + _t; _d <= n; ++_d)
        {
            dp[d] = max(dp[d], dp[_d] + _p);
        }
        result = max(result, dp[d]);
    }

    cout << result << "\n";

    return 0;
}