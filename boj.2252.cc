#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_STUDENT = 32000;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, degree[MAX_STUDENT] = {0};
    cin>>n>>m;

    vector<vector<int>> edges(n);
    for(int i = 0, a, b; i<m; ++i)
    {
        cin>>a>>b;
        --a, --b;
        edges[a].push_back(b);
        ++degree[b];
    }

    queue<int> q;
    for(int i = 0; i<n; ++i)
    {
        if(!degree[i])
        {
            q.push(i);
        }
    }

    while(!q.empty()) 
    {
        int tgt = q.front();
        q.pop();

        for(auto av: edges[tgt])
        {
            if(!(--degree[av]))
            {
                q.push(av);
            }
        }

        cout<<tgt+1<<" ";
    }

    return 0;
}