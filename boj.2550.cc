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

cll MAX_N = 1e5;
ll n, switches[MAX_N + 1] = {}, lights[MAX_N + 1] = {},
                       dp[MAX_N + 1] = {}, bt[MAX_N + 1] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll _switch, i = 1; i <= n; ++i)
    {
        cin >> switches[i];
    }
    for (ll _light, i = 1; i <= n; ++i)
    {
        cin >> _light;
        lights[_light] = i;
    }

    dp[0] = 0, bt[0] = 0;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll l = 0; l < i; ++l)
        {
            if (lights[switches[l]] < lights[switches[i]] && dp[i] < dp[l] + 1)
            {
                dp[i] = dp[l] + 1, bt[i] = l;
            }
        }
    }

    ll resultIdx = 0;
    vll v;
    for (ll i = 0; i <= n; ++i)
    {
        if (dp[resultIdx] < dp[i])
        {
            resultIdx = i;
        }
    }
    while (resultIdx)
    {
        v.push_back(switches[resultIdx]);
        resultIdx = bt[resultIdx];
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (auto &r : v)
    {
        cout << r << " ";
    }

    return 0;
}