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

cll MAX_N = 1e5, MAX_K = 1e3, MAX_M = 1e3; 
ll n, k, m, hypers[MAX_N] = {}, mat[MAX_N] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k>>m;
    vector<vll> stations(m, vll(k));
    vector<vll> hypers(n);
    for(ll i = 0; i<m; ++i)
    {
        for(ll l = 0; l<k; ++l)
        {
            cin>>stations[i][l];
            hypers[--stations[i][l]].push_back(i);
        }
    }

    qll q;
    mat[0] = 1;
    q.push(0);

    while(!q.empty())
    {
        ll s = q.front();
        // cout<<s<<" "<<hypers[s]<<"\n";
        q.pop();
        for(auto &_h: hypers[s])
        {
            for(auto &_s: stations[_h])
            {
                if(!mat[_s])
                {
                    mat[_s] = mat[s] + 1;
                    q.push(_s);
                }
            }
        }
    }

    cout<<(mat[n-1]?mat[n-1]:-1)<<"\n";


    return 0;
}