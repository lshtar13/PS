#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 987654321

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<pair<int, int>>> edges(n);
    vector<int> dis(n, INF);
    vector<bool> visited(n, false);
    vector<int> pre(n,-1);
    for(int i = 0, a, b, c; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        edges[--a].push_back(make_pair(--b, c));
    }

    int s, e;
    scanf("%d %d", &s, &e);
    --s, --e;

    priority_queue<pair<int,int>,vector<pair<int,int> >,
                    greater<pair<int,int> > >pq;
    dis[s] = 0;
    pq.push(make_pair(0, s));

    while(!pq.empty())
    {
        int vertex = pq.top().second, distance = pq.top().first;
        pq.pop();

        if(visited[vertex])
        {
            continue;
        }

        for(auto edge: edges[vertex])
        {
            int v = edge.first, w = edge.second;
            if(distance + w < dis[v])
            {
                pre[v] = vertex, dis[v] = distance + w;
                pq.push(make_pair(distance+w, v));
            }
        }

        visited[vertex] = true;
    }

    printf("%d\n", dis[e]);
    int vertex = e;
    vector<int> cities;
    while(vertex != -1)
    {
        cities.push_back(vertex);
        vertex = pre[vertex];
    }

    printf("%ld\n", cities.size());
    for(int i = cities.size()-1; i>=0; --i)
    {
        printf("%d ", cities[i]+1);
    }

    return 0;
}