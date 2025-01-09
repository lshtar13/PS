#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int findRoot(vector<int> &graph, int n)
{
    return graph[n] = graph[n] == n ? n : findRoot(graph, graph[n]);
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> graph(n+1);
    for(int i=0; i<n+1; ++i)
    {
        graph[i] = i;
    }

    for(int i = 1; i<=n; ++i)
    {
        for(int j = 1; j<=n; ++j)
        {
            int connected;
            scanf("%d", &connected);

            if(connected)
            {
               int rootI = findRoot(graph, i), rootJ = findRoot(graph, j);
               if(rootI != rootJ)
               {
                graph[rootI] = rootJ;
               }
            }
        }
    }

    int pre;
    scanf("%d", &pre);
    for(int i = 1, current; i<m; ++i, pre = current)
    {
        scanf("%d", &current);
        if(findRoot(graph, pre)!=findRoot(graph, current))
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");
    return 0;
}