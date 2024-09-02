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

cll MAX_N = 1000, MAX_D = 1000, MAX_W = 1e8;
ll n, m, info[MAX_N + 1][2] = {{}}, dp[MAX_N + 1][MAX_N + 1][2] = {{}};
// dp[i][l][0] ==> i번째에 l을 갔을 때, l 도착 시점까지 낭비된 전력량
// dp[i][l][1] ==> i번째에 l을 갔을 때, 남은 지점들의 소비 전력 합

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll sum = 0;
    cin >> n >> m;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> info[i][0] >> info[i][1];
        sum += info[i][1];
    }
    sum -= info[m][1];

    for (ll l = 1; l <= n; ++l)
    {
        dp[2][l][0] = sum * abs(info[m][0] - info[l][0]),
        dp[2][l][1] = sum - info[l][1];
    }

    for (ll i = 3; i <= n; ++i)
    {
        for (ll l = 1; l <= n; ++l)
        {
            if(l == m)
            {
                continue;
            }

            dp[i][l][0] = LLONG_MAX;
            for(ll _l = 1; _l <= n; ++_l)
            {
                if(_l == m || _l == l)
                {
                    continue;
                }
            }
        }
    }

    return 0;
}