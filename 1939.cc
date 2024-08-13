#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, m, tgt0, tgt1;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    vector<map<ll, ll>> edges(n);
    for(ll a, b, c, i = 0; i<m; ++i)
    {
        cin>>a>>b>>c;
        --a, --b;

        edges[a][b] = max(edges[a][b], c);
        edges[b][a] = max(edges[b][a], c);
    }
    cin>>tgt0>>tgt1;
    --tgt0, --tgt1;

    vector<ll> maxWeight(n, 0);
    queue<ll> q;
    q.push(tgt0);
    maxWeight[tgt0] = 1e9;
    while(!q.empty())
    {
        ll node = q.front();
        q.pop();
        for(auto it: edges[node])
        {
            ll next = it.first, limit = it.second, newWeight = min(maxWeight[node], limit);
            if(maxWeight[next] < newWeight)
            {
                maxWeight[next] = newWeight;
                q.push(next);
            }
        }
    }

    cout<<maxWeight[tgt1]<<"\n";

    return 0;
}