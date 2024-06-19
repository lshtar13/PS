#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 987654321
int main(void)
{
    int v, e, k;
    scanf("%d %d %d", &v, &e, &k);

    vector<pair<int, int>> edges[20009];
    for(int i = 0, u, v, w; i<e; ++i)
    {
        scanf("%d %d %d", &u, &v, &w);
        edges[u-1].push_back(make_pair(v-1,w));
    }

    vector<int> d(v,INF);
    d[k-1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,
                    greater<pair<int,int> > >pq;
    pq.push(make_pair(0, k-1));
    while(!pq.empty())
    {
        int vertex = pq.top().second, distance = pq.top().first;
        pq.pop();
        // printf("%d : ", vertex);

        for(int i = 0; i<edges[vertex].size(); ++i)
        {
            pair<int,int> edge = edges[vertex][i];
            int av = edge.first, w = edge.second;
            // printf("%d ", av);
            if(w+distance < d[av])
            {
                d[av] = w + distance;
                pq.push(make_pair((w + distance), av));
            }
        }

        // printf("\n");
    }

    for(auto distance: d)
    {
        printf("%s\n", 
        (distance != INF? to_string(distance) : string("INF")).c_str());
    }

    return 0;
}