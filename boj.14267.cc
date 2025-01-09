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
typedef vector<vll> vvll;

cll MAX_N = 1e5;
ll n, m, weights[MAX_N+1] = {}, parent[MAX_N+1] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(ll master, i = 1; i<=n; ++i)
    {
        cin>>master;
        if(master>0)
        {
            parent[i] = master;
        }
    }

    for(ll num, w, i = 0; i<m; ++i)
    {
        cin>>num>>w;
        weights[num] += w;
    }

    for(ll i = 1; i<=n; ++i)
    {
        weights[i] += weights[parent[i]];
        cout<<weights[i]<<" ";
    }
    cout<<"\n";

    return 0;
}