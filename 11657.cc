#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 98765432111 

vector<ll>
bellman_ford(vector<vector<pair<ll, ll>>> &edges, ll n, ll s)
{
    vector<ll> distance(n, INF);
    distance[s] = 0;

    for(ll a = 0; a < n-1; ++a)
    for(ll i = 0; i < n; ++i)
    {
        for(auto edge: edges[i])
        {
            ll v = edge.first, w = edge.second;
            if(distance[i]!=INF && distance[i] + w < distance[v])
            {
                distance[v] = distance[i] + w;
            }
        }
    }
    
    for(ll a = 0; a < n-1; ++a)
    for(ll i = 0; i < n; ++i)
    {
        for(auto edge: edges[i])
        {
            ll v = edge.first, w = edge.second;
            if(distance[i]!=INF && distance[i] + w < distance[v])
            {
                distance[s] = INF;
                return distance;
            }
        }
    }

    return distance;
}

int main(void)
{
    ll n, m;
    scanf("%lld %lld", &n, &m);

    vector<vector<pair<ll, ll>>> edges(n);
    for(ll i = 0, a, b, c; i<m; ++i)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        --a, --b;
        edges[a].push_back(make_pair(b, c));
    }

    vector<ll> distance = bellman_ford(edges, n, 0);
    if(distance[0] == INF)
    {
        printf("-1");
    }
    else
    {
        for(ll i = 1;i<n; ++i)
        {
            printf("%lld\n", distance[i] == INF ? -1 : distance[i]);
        }
    }
    return 0;
}