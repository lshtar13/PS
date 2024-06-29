#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int v;
    scanf("%d",&v);

    vector<vector<pair<int, int>>> edges(v);
    for(int i = 0, node, a, b; i<v; ++i)
    {
        scanf("%d", &node);
        --node;
        while(true)
        {
            scanf("%d", &a);
            if(a == -1)
            {
                break;
            }
            --a;
            scanf("%d", &b);
            edges[node].push_back(make_pair(a, b));
        }
    }

    vector<int> distance(v, -1);
    queue<int> q;
    int maxNode = 0, maxLen = 0;
    q.push(0);
    distance[0] = 0;

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto avi: edges[node])
        {
            int av = avi.first, w = avi.second; 
            if(distance[av] != -1)
            {
                continue;
            }
            distance[av] = distance[node] + w;
            q.push(av);
            if(maxLen < distance[av])
            {
                maxNode = av, maxLen = distance[av];
            }
        }
    }

    fill(distance.begin(), distance.end(), -1);
    maxLen = 0, distance[maxNode] = 0;
    q.push(maxNode);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(auto avi: edges[node])
        {
            int av = avi.first, w = avi.second;
            if(distance[av] != -1)
            {
                continue;
            }
            maxLen = max(maxLen, distance[av] = distance[node] + w);
            q.push(av);
        }
    }

    printf("%d", maxLen);

    return 0;
}