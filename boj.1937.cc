#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

ll n, mat[500][500] = {}, dp[500][500] = {}, direct[4][2] = {{0, 1}, {0 , -1}, {1, 0}, {-1, 0}};

ll search(ll i, ll l)
{
    if(dp[i][l] != -1)
    {
        return dp[i][l];
    }

    dp[i][l] = 1;
    for(ll d = 0, _i = direct[d][0] + i, _l = direct[d][1] + l; d<4;
        ++d, _i = direct[d][0] + i, _l = direct[d][1] + l)
    {
        if(!(_i>=0 && _i<n && _l>=0 && _l<n))
        {
            continue;
        }
        if(mat[_i][_l]>mat[i][l])
        {
            dp[i][l] = max(dp[i][l], search(_i, _l) + 1);
        }
    }

    return dp[i][l];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));
    cin>>n;
    for(ll i = 0; i<n; ++i)
    {
        for(ll l = 0; l<n; ++l)
        {
            cin>>mat[i][l];
        }
    }

    ll result = 0;
    for(ll i = 0; i<n; ++i)
    {
        for(ll l = 0; l<n; ++l)
        {
            result = max(result, search(i, l));
        }
    }

    cout<<result<<"\n";

    return 0;
}