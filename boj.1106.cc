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

cll MAX_C = 1000, MAX_N = 20;
ull c, n, cities[MAX_N+1][2] = {{}}, dp[MAX_N+1][1101] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>c>>n;
    for(ll i = 1; i<=n; ++i)
    {
        cin>>cities[i][0]>>cities[i][1];
    }
    memset(dp, -1, sizeof(dp));

    dp[0][0] = 0;
    for(ll i = 1; i<=n; ++i)
    {
        for(ll _c = 0; _c<1101; ++_c)
        {
            dp[i][_c] = dp[i-1][_c];
            for(ll a = cities[i][0], b = cities[i][1]; b<=_c; a += cities[i][0], b += cities[i][1])
            {
                if(dp[i-1][_c-b] == -1)
                {
                    continue;
                }
                dp[i][_c] = min(dp[i][_c], dp[i-1][_c-b] + a);
            }
            // cout<<i<<" "<<_c<<" "<<dp[i][_c]<<"\n";
        }
    }
    
    ull result = -1;
    for(ll _c = c; _c<1101; ++_c)
    {
        if(dp[n][_c]!=-1)
        {
            result = min(result, dp[n][_c]);
        }
    }

    cout<<result<<"\n";

    return 0;
}