#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<pair<ll, ll>, ll> boxInfo;

ll n, c, m, dCap[2000] = {0}; 
boxInfo infos[10000]; // to, nbox

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>c>>m;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll, ll>>> pq;
    for(ll from, to, nBox, i = 0; i<m; ++i)
    {
        cin>>from>>to>>nBox;
        --from, --to;
        infos[i].first.first = from, infos[i].first.second = to,
        infos[i].second = nBox;
        pq.push(make_pair(to, i));
    }

    ll result = 0;
    while(!pq.empty())
    {
        ll idx = pq.top().second,
            from = infos[idx].first.first, to = infos[idx].first.second, nBox = infos[idx].second;

        for(ll town = from; town<to; ++town)
        {
            nBox = min(nBox, c - dCap[town]);
        }
        for(ll town = from; town<to; ++town)
        {
            dCap[town] += nBox;
        }

        result += nBox;
        pq.pop();
    }

    cout<<result<<"\n";

    return 0;
}