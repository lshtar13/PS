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
typedef unsigned short us;

ll n, info[50][3] = {{}};
map<pair<pll, ll>, ll> dp;

ll solve(ll it, ll pt, ll q)
{
    it %= 1001, pt %= 1001;
    if (dp.find(make_pair(make_pair(it, pt), q)) != dp.end())
    {
        return dp[make_pair(make_pair(it, pt), q)];
    }

    ll result = 0;
    for (ll _q, i = 0; i < n; ++i)
    {
        _q = 1 << i;
        if (_q & q)
        {
            continue;
        }

        if (info[i][0] <= it || info[i][1] <= pt)
        {
            result = max(result, 1 + solve(it + info[i][2], pt, _q | q));
            result = max(result, 1 + solve(it, pt + info[i][2], _q | q));
        }
    }

    return dp[make_pair(make_pair(it, pt), q)] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }

    cout << solve(1, 1, 0);

    return 0;
}