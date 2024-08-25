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

cll MAX_N = 300;
ll n, w[MAX_N] = {}, mat[MAX_N][MAX_N] = {{}}, uf[MAX_N] = {}, isIn[MAX_N] = {};

ll find(ll node)
{
    if(uf[node] == node)
    {
        return node;
    }
    else
    {
        return uf[node] = find(uf[node]);
    }
}

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin>>n;
    for(ll i = 0; i<n; ++i)
    {
        cin>>w[i];
        uf[i] = i;
    }
    priority_queue<pair<ll, pll>> pq;
    for(ll i = 0; i<n; ++i)
    {
        for(ll _p, l = 0; l<n; ++l)
        {
            cin>>_p;
            if(i<l)
            {
                pq.push(make_pair(-_p, make_pair(i, l)));
            }
        }
    }

    while(!pq.empty())
    {
        ll weight = -pq.top().first, i = pq.top().second.first, l = pq.top().second.second;
        pq.pop();
        if(find(i) == find(l))
        {
            continue;
        }

        mat[i][l] = mat[l][i] = weight;
        uf[l] = uf[i];
    }

    ll start = 0, result = w[start];
    for(ll i = 0; i<n; ++i)
    {
        if(w[i]<w[start])
        {
            result = w[start = i];
        }
    }

    qll q;
    q.push(start);
    isIn[start] = 1;
    while(!q.empty())
    {
        ll i = q.front();
        q.pop();
        for(ll l = 0; l<n; ++l)
        {
            if(!isIn[l] && mat[i][l])
            {
                result += mat[i][l] < w[l] ? mat[i][l] : w[l];
                q.push(l);
                isIn[l] = 1;
            }
        }
    }

    cout<<result<<"\n";

    return 0;
}