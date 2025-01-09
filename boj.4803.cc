#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(int n, vector<vector<int>> &edges)
{
    int result = 0;
    vector<int> visited(n, -1);
    for(int i = 0; i<n; ++i)
    {
        if(visited[i]!=-1)
        {
            continue;
        }

        bool isTree = true;
        queue<int> q;
        q.push(i);
        visited[i] = 0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto av: edges[node])
            {
                if(av == visited[node])
                {
                    continue;
                }
                else if(visited[av]!= -1)
                {
                    // printf(" ==> (%d, %d) ", node, av);
                    isTree = false;
                    continue;
                }

                q.push(av);
                visited[av] = node;
            }
        }

        if(isTree)
        {
            ++result;
        }
    }

    return result;
}

int main(void)
{
    for(int t = 1, n, m; cin>>n>>m && (n!=0 || m!=0); ++t)
    {
        int result;
        vector<vector<int>> edges(n);
        for(int i = 0, a, b; i<m; ++i)
        {
            scanf("%d %d", &a, &b);
            --a, --b;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        switch(result = solve(n, edges))
        {
            case 0:
                printf("Case %d: No trees.\n", t);
                break;
            case 1:
                printf("Case %d: There is one tree.\n", t);
                break;
            default:
                printf("Case %d: A forest of %d trees.\n", t, result);
                break;
        }
    }
    return 0;
}