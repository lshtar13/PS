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

cll MAX_N = 5000, MAX_M = 1e5;
ll n, m, h[MAX_N+1] = {}, dp[MAX_N+1] = {};
vll mat[MAX_N+1];

ll search(ll k)
{
    if(dp[k])
    {
        return dp[k];
    }
    
    dp[k] = 0;
    for(auto &m : mat[k])
    {
        dp[k] = max(dp[k], search(m));
    }
    
    return ++dp[k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(ll i = 1; i<=n; ++i)
    {
        cin>>h[i];
    }

    for(ll a, b, i = 0; i<m; ++i)
    {
        cin>>a>>b;
        if(h[a]<h[b])
        {
            mat[a].push_back(b);
        }
        else
        {
            mat[b].push_back(a);
        }
    }

    for(ll i = 1; i<=n; ++i)
    {
        cout<<search(i)<<"\n";
    }


    return 0;
}