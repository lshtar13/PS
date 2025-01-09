#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<vector<int>> edges(n);
    for(int i = 0, a, b; i<n-1; ++i) 
    {
        scanf("%d %d", &a, &b);
        edges[--a].push_back(--b);
        edges[b].push_back(a);
    }

    vector<int> parent(n, -1);
    queue<int> q;
    q.push(0);
    
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto av: edges[node])
        {
            if(parent[av] == -1)
            {
                parent[av] = node;
                q.push(av);
            }
        }
    }

    for(int i = 1; i<n; ++i)
    {
        printf("%d\n", parent[i]+1);
    }

    return 0;
}