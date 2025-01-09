#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef vector<ll> vll;
typedef queue<ll> qll;

cll MAX_N = 1000;
ll n, m, mat[MAX_N][MAX_N] = {{}}, degree[MAX_N] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(ll k, i = 0; i<m; ++i)
    {
        cin>>k;
        vll former;
        for(ll s, l = 0; l<k; ++l)
        {
            cin>>s;
            --s;
            for(auto &_s: former)
            {
                if(!mat[_s][s])
                {
                    mat[_s][s] = 1, ++degree[s];
                }
            }
            former.push_back(s);
        }
    }

    qll q; 
    for(ll s = 0; s<n; ++s)
    {
        if(!degree[s])
        {
            q.push(s);
        }
    }

    vll result;
    while(!q.empty())
    {
        ll s = q.front();
        result.push_back(s); 
        for(ll _s = 0; _s<n; ++_s)
        {
            if(mat[s][_s] && !--degree[_s])
            {
                q.push(_s);
            }
        }
        q.pop();
    }

    if(result.size() != n)
    {
        cout<<0<<"\n";
    }
    else
    {
        for(auto &s: result)
        {
            cout<<s+1<<"\n";
        }
    }

    return 0;
}