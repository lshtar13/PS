#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int findRoot(int graph[], int p)
{
    return graph[p] = graph[p] == p ? p : findRoot(graph, graph[p]);
}

bool merge(int graph[], int p0, int p1)
{
    int root0 = findRoot(graph, p0), root1 = findRoot(graph, p1);
    if(root0 == root1)
    {
        return false;
    }

    graph[root1] = root0;
    return true;
}

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, result = 0, graph[500000];
    // scanf("%d %d", &n, &m);
    cin>>n>>m;

    for(int i = 0; i<n; ++i)
    {
        graph[i] = i;
    }

    for(int i = 1, p0, p1; i<=m; ++i)
    {
        // scanf("%d %d", &p0, &p1);
        cin>>p0>>p1;
        if(!merge(graph, p0, p1))
        {
            result = i;
            break;
        }
    }
    // printf("%d",result);
    cout<<result;
    return 0;
}