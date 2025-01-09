#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll INF = 1e9;
ll n, m, x, edges0[1000][1000] = {{0}}, edges1[1000][1000] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>x;
    --x;

    for(ll from, to, t, i = 0; i<m; ++i)
    {
        cin>>to>>from>>t;
        edges0[--from][--to] = t;
        edges1[to][from] = t;
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> cost0(n, INF);
    cost0[x] = 0;
    pq.push(make_pair(0, x));
    while(!pq.empty())
    {
        ll node = pq.top().second, t = pq.top().first;
        pq.pop();

        if(t != cost0[node])
        {
            continue;
        }

        for(ll newCost, next = 0; next<n; ++next)
        {
            if(!edges0[node][next])
            {
                continue;
            }

            newCost = t + edges0[node][next];
            if(newCost < cost0[next])
            {
                pq.push(make_pair(cost0[next] = newCost, next));
            }
        }
    }
    
    vector<ll> cost1(n, INF);
    cost1[x] = 0;
    pq.push(make_pair(0, x));
    while(!pq.empty())
    {
        ll node = pq.top().second, t = pq.top().first;
        pq.pop();

        if(t != cost1[node])
        {
            continue;
        }

        for(ll newCost, next = 0; next<n; ++next)
        {
            if(!edges1[node][next])
            {
                continue;
            }

            newCost = t + edges1[node][next];
            if(newCost < cost1[next])
            {
                pq.push(make_pair(cost1[next] = newCost, next));
            }
        }
    }

    ll result = 0;
    for(int i = 0; i<n; ++i)
    {
        result = max(result, cost0[i] + cost1[i]);
    }

    cout<<result<<"\n";

    return 0;
}