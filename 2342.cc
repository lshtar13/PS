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

cll MAX_LEN = 1e5, MAX_DIR = 5;
ull str[MAX_LEN+1] = {}, strLen, dp[MAX_LEN+1][MAX_DIR][MAX_DIR] = {{{}}};

ll solve(ll step, ll l, ll r)
{
    if(dp[step][l][r]>=0)
    {
        return dp[step][l][r];
    }

    ll _l, _r;
    _l = str[step], _r = r;
    
    _l = l, _r = str[step];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(strLen = 0; cin>>str[++strLen] && str[strLen];)
    {}
    memset(dp, -1, sizeof(dp));

    cout<<solve(1, 0, 0)<<"\n";

    return 0;
}