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

cll MAX_N = 300, MAX_M = MAX_N, INF = 30001;
ll n, m, beads[MAX_N + 1] = {}, sum[MAX_N + 1] = {},
                       dp[MAX_M + 1][MAX_N + 1] = {{}}, track[MAX_M + 1][MAX_N + 1] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> beads[i];
        dp[i][i] = max(beads[i], dp[i - 1][i - 1]), track[i][i] = i - 1;
        dp[1][i] = dp[1][i - 1] + beads[i], track[1][i] = 0;
    }

    for (ll _m = 2; _m <= m; ++_m)
    {
        for (ll _n = _m + 1; _n <= n; ++_n)
        {
            dp[_m][_n] = INF;
            for (ll mv, i = _n - 1; i >= _m - 1; --i)
            {
                mv = max(dp[_m - 1][i], dp[1][_n] - dp[1][i]);
                if (dp[_m][_n] > mv)
                {
                    dp[_m][_n] = mv, track[_m][_n] = i;
                }
            }
        }
    }

    cout << dp[m][n] << "\n";
    ll t = n;
    stack<ll> s;
    for (ll _m = m; _m > 0; --_m)
    {
        s.push(t - track[_m][t]);
        t = track[_m][t];
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}