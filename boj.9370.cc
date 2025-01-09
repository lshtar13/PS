#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 987654321

pair<vector<int>, vector<int>>
dijkstra(vector<vector<pair<int, int>>> &edges, int n, int s)
{
    vector<int> d(n, INF);
    vector<int> p(n, -1);
    d[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int,int>>,
                      greater<pair<int,int>>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty())
    {
        int vertex = pq.top().second, distance = pq.top().first;
        pq.pop();

        for(auto edge: edges[vertex])
        {
            int next_vertex = edge.first, w = edge.second, new_w;
            if(d[next_vertex] > (new_w = w+distance))
            {
                d[next_vertex] = new_w, p[next_vertex] = vertex;
                pq.push(make_pair(new_w, next_vertex));
            }
        }
    }
    return make_pair(d, p);
}

void solve(void)
{
    int n, m, t, s, g, h;
    scanf("%d %d %d %d %d %d", &n, &m, &t, &s, &g, &h);
    --s, --g, --h;

    vector<vector<pair<int, int>>> edges(2000);
    for(int i = 0, a, b, d; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &d);
        edges[--a].push_back(make_pair(--b, d));
        edges[b].push_back(make_pair(a, d));
    }

    pair<vector<int>, vector<int>> dijkstra0 = dijkstra(edges, n, s);
    vector<int> d = dijkstra0.first, p = dijkstra0.second; 

    priority_queue<int, vector<int>, greater<int>> result;
    for(int i = 0, vertex; i<t; ++i)
    {
        scanf("%d", &vertex);
        if(p[--vertex] == -1)
        {
            continue;
        }

        pair<vector<int>, vector<int>> dijkstra_g = dijkstra(edges, n, g),
            dijkstra_h = dijkstra(edges,n,h);
        vector<int> d_g = dijkstra_g.first, p_g = dijkstra_g.second,
            d_h = dijkstra_h.first, p_h = dijkstra_h.second; 

        if(d[vertex] == d[g] + d_g[h] + d_h[vertex] ||
            d[vertex] == d[h] + d_h[g] + d_g[vertex])
        {
            result.push(vertex);
        }
    }

    while(!result.empty())
    {
        printf("%d ", result.top()+1);
        result.pop();
    }

    printf("\n");
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        solve();
    }
    return 0;
}