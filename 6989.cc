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

cll MAX_N = 150, MAX_SCORE_PER_PROBLEM = 100,
    MAX_SCORE = MAX_N * MAX_SCORE_PER_PROBLEM;
ll n, scores[MAX_N + 1] = {}, sum[MAX_N + 1] = {}, k,
                     dp[MAX_N + 1][2][MAX_SCORE + 1] = {{{}}}, dpScore[MAX_N + 1][MAX_SCORE + 1];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> scores[i];
        sum[i] = scores[i] + sum[i - 1];
    }
    cin >> k;

    dp[0][0][0] = dp[0][1][0] = -1;
    for (ll p = 1; p <= n; ++p)
    {
        for (ll _s, s = 0; s <= MAX_SCORE; ++s)
        {
            if (dp[p - 1][0][s] || dp[p - 1][1][s])
            {
                dp[p][0][s] = -1;
            }
            if ((_s = s + scores[p]) <= MAX_SCORE && dp[p - 1][0][s])
            {
                dp[p][1][_s] = scores[p];
            }
            for (ll _s, _sum, i = 0; i < p - 1; ++i)
            {
                _sum = sum[p] - sum[i];
                if ((_s = _sum + s) <= MAX_SCORE && dp[p - 1][1][s] == sum[p - 1] - sum[i])
                {
                    dp[p][1][_s] = _sum;
                }
            }
        }
    }

    for (ll s = k; s <= MAX_SCORE; ++s)
    {
        if (!(dp[n][0][s] || dp[n][1][s]))
        {
            cout << s << " ";
            break;
        }
    }

    return 0;
}