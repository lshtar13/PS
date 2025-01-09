#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, root, tgt;
    cin>>n>>root>>tgt;
    --root, --tgt;

    vector<vector<pair<ll, ll>>> edges(n);
    vector<pair<ll, ll>> dis(n, make_pair(0, 0));
    for(int x,y,z,i = 0; i<n-1; ++i)
    {
        cin>>x>>y>>z;
        --x,--y;

        edges[x].push_back(make_pair(y, z));
        edges[y].push_back(make_pair(x, z));
    }

    dis[root] = make_pair(0, 0);
    queue<pair<ll, ll>> q;
    q.push(make_pair(root, -1));

    while(!q.empty())
    {
        ll node = q.front().first, parent = q.front().second;
        for(auto av: edges[node])
        {
            if(av.first!=parent)
            {
                ll dist = av.second;
                dis[av.first].first = dis[node].first + dist;
                dis[av.first].second = max(dis[node].second, dist);
                q.push(make_pair(av.first, node));
            }
        }
        q.pop();
    }

    cout<<dis[tgt].first - dis[tgt].second<<"\n";

    return 0;
}