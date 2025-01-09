#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, m, x, degree[100000] = {0}, called[100000] = {0}, result[100000][2] = {{0}}, ncalled = 0;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>x;
    vector<vector<ll>> edges(n);

    for(ll a, b, i = 0; i<m; ++i)
    {
        cin>>a>>b;
        --a, --b;

        edges[a].push_back(b);
        ++degree[b], called[a] = called[b] = 1;
    }

    queue<ll> q;
    for(ll i = 0; i<n; ++i)
    {
        if(!called[i])
        {
            ++ncalled;
        }
        else if(!degree[i])
        {
            q.push(i);
        }
    }


    ll rank = 1;
    while(!q.empty())
    {
        ll minRank = rank, maxRank = rank;
        vector<ll> students;
        for(ll i  = 0; !q.empty(); maxRank = rank += i++)
        {
            students.push_back(q.front());
            q.pop();
        }

        for(auto s: students)
        {
            result[s][0] = max(ll(1), minRank-ncalled), result[s][1] = min(n, maxRank+ncalled);
            for(auto av: edges[s])
            {
                if(!--degree[av])
                {
                    q.push(av);
                }
            }
        }
    }

    --x;
    if(called[x])
    {
        cout<<result[x][0]<<" "<<result[x][1]<<"\n";
    }
    else
    {
        cout<<1<<" "<<n<<"\n";
    }

    return 0;
}