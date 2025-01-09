#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve()
{
    int n;
    cin>>n;
    int degree[501] = {0};
    char isFront[501] = {0}, edges[501][501] = {{0}};
    for(int i = 0, team; i<n; ++i)
    {
        cin>>team;
        isFront[team] = 1;
        for(int t = 1; t<=n; ++t)
        {
            if(!isFront[t])
            {
                edges[team][t] = 1, ++degree[t];
            }
        }
    }

    int m;
    cin>>m;
    for(int i = 0, a, b; i<m; ++i)
    {
        cin>>a>>b;
        if(edges[a][b] && !edges[b][a])
        {
            edges[a][b] = 0, edges[b][a] = 1;
            --degree[b], ++degree[a];
        }
        else if(edges[b][a] && !edges[a][b])
        {
            edges[b][a] = 0, edges[a][b] = 1;
            --degree[a], ++degree[b];
        }
    }

    queue<int> q;
    for(int t = 1; t<=n; ++t)
    {
        if(!degree[t])
        {
            q.push(t);
        }
    }

    vector<int> result;
    while(q.size()==1) 
    {
        int tgt = q.front();
        q.pop();

        for(int av = 1; av<=n; ++av)
        {
            if(edges[tgt][av] && !(--degree[av]))
            {
                q.push(av);
            }
        }
        result.push_back(tgt);
    }

    if(q.size()>1)
    {
        cout<<"?"<<"\n";
    }
    else if(result.size()!=n)
    {
        cout<<"IMPOSSIBLE"<<"\n";
    }
    else
    {
        for(auto t: result)
        {
            cout<<t<<" ";
        }
        cout<<"\n";
    }

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}