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

cll MAX_N = 1000, MAX_M = 500, MAX_K = 10000;
ll n, m, k, cards[MAX_N+1] = {}, roads[MAX_M+1][MAX_M+1] = {{}}, dp[MAX_N+1][MAX_M+1] = {{}};

ll search(ll c, ll v)
{
    if(dp[c][v]!=-1)
    {
        return dp[c][v];
    }

    dp[c][v] = 0;
    for(ll _v = 1; c<=n && _v<=m; ++_v)
    {
        if(roads[v][_v] == cards[c])
        {
            dp[c][v] = max(dp[c][v], 10 + search(c+1, _v));
        }
        else if(roads[v][_v])
        {
            dp[c][v] = max(dp[c][v], search(c+1, _v));
        }
    }

    return dp[c][v];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin>>n;
    for(ll i = 1; i<=n; ++i)
    {
        char c;
        cin>>c;
        cards[i] = c;
    }

    cin>>m>>k;
    for(ll a, b, i = 0; i<k; ++i)
    {
        char c;
        cin>>a>>b>>c;
        roads[a][b] = roads[b][a] = c;
    }

    cout<<search(1, 1)<<"\n";

    return 0;
}