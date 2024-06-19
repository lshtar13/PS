#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 987654321 

int main(void)
{
    int n,e,v1,v2;
    scanf("%d %d", &n, &e);
    vector<pair<int, int>> edges[800];
    for(int i = 0, a, b, c; i<e; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        edges[a-1].push_back(make_pair(b-1, c));
        edges[b-1].push_back(make_pair(a-1, c));
    }

    scanf("%d %d",&v1, &v2);

    int start_v1, start_v2, v1_v2, v1_end, v2_end;

    vector<int> d_start(n, INF), d_v1(n, INF), d_v2(n, INF);
    vector<int> p_start(n, -1), p_v1(n, -1), p_v2(n, -1);
    d_start[0] = 0, d_v1[v1-1] = 0, d_v2[v2-1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,
                    greater<pair<int,int> > >pq;
    pq.push(make_pair(0, 0));
    while(!pq.empty())
    {
        int vertex = pq.top().second, distance = pq.top().first;
        pq.pop();

        for(int i = 0; i<edges[vertex].size(); ++i)
        {
            pair<int,int> edge = edges[vertex][i];
            int av = edge.first, w = edge.second;
            if(w+distance < d_start[av])
            {
                d_start[av] = w + distance, p_start[av] = vertex;
                pq.push(make_pair((w + distance), av));
            }
        }
    }
    start_v1 = d_start[v1-1], start_v2 = d_start[v2-1];
    
    pq.push(make_pair(0, v1-1));
    while(!pq.empty())
    {
        int vertex = pq.top().second, distance = pq.top().first;
        pq.pop();

        for(int i = 0; i<edges[vertex].size(); ++i)
        {
            pair<int,int> edge = edges[vertex][i];
            int av = edge.first, w = edge.second;
            if(w+distance < d_v1[av])
            {
                d_v1[av] = w + distance, p_v1[av] = vertex;
                pq.push(make_pair((w + distance), av));
            }
        }
    }
    v1_v2 = d_v1[v2-1], v1_end = d_v1[n-1];
    
    pq.push(make_pair(0, v2-1));
    while(!pq.empty())
    {
        int vertex = pq.top().second, distance = pq.top().first;
        pq.pop();

        for(int i = 0; i<edges[vertex].size(); ++i)
        {
            pair<int,int> edge = edges[vertex][i];
            int av = edge.first, w = edge.second;
            if(w+distance < d_v2[av])
            {
                d_v2[av] = w + distance, p_v2[av]=vertex;
                pq.push(make_pair((w + distance), av));
            }
        }
    }
    v2_end = d_v2[n-1];

    int prev = v1-1, result = INT_MAX;
    while(p_start[prev] != -1 && p_start[prev] != 0)
    {
        if((prev = p_start[prev]) == v2-1 && start_v1 != INF && v1_end != INF)
        {
           result = min(result, start_v1+v1_end);
           break;
        }
    }

    prev = v2-1;
    while(p_start[prev] != -1 && p_start[prev] != 0)
    {
        if((prev = p_start[prev]) == v1-1 && start_v2 != INF && v2_end != INF)
        {
           result = min(result, start_v2+v2_end);
           break;
        }
    }

    if(start_v1 != INF && v1_v2 != INF && v2_end != INF)
    {
        result = min(result, start_v1 + v1_v2 + v2_end);
    }

    if(start_v2 != INF && v1_v2 != INF && v1_end != INF)
    {
        result = min(result, start_v2 + v1_v2 + v1_end);
    }

    if(result == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d", result);
    }

    return 0;
}