#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 987654321

void printCost(vector<vector<int>> &cost, int n)
{
    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<n; ++l)
        {
            printf("%d ", cost[i][l]!=INF?cost[i][l]:0);
        }
        printf("\n");
    }
}

void printPath(vector<vector<vector<int>>> &paths, int n,
        vector<vector<int>> &cost)
{
    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<n; ++l)
        {
            if(!cost[i][l] || cost[i][l] == INF)
            {
                printf("0\n");
            }
            else
            {
                vector<int> &path = paths[i][l];
                printf("%ld ", path.size()+2);
                printf("%d ", i+1);
                for(auto city: path)
                {
                    printf("%d ", city+1);
                }
                printf("%d\n", l+1);
            }
        }
    }
}

int main(void)
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<int>> cost(n, vector<int>(n, INF));
    vector<vector<vector<int>>> path(n, 
                vector<vector<int>>(n));
    for(int i = 0; i<n; ++i)
    {
        cost[i][i] = 0;
    }

    for(int i = 0, a, b, c; i<m; ++i)
    {
        scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = min(cost[--a][--b], c);
    }

    for(int midium =0; midium<n; ++midium)
    {
        for(int i = 0; i<n; ++i)
        {
            for(int l = 0; l<n; ++l)
            {
                // cost[i][l] = min(cost[i][l], 
                //                 cost[i][midium] + cost[midium][l]);
                if(cost[i][l] > cost[i][midium] + cost[midium][l])
                {
                    cost[i][l] = cost[i][midium] + cost[midium][l];
                    path[i][l].clear();
                    path[i][l].reserve(path[i][midium].size() + path[midium][l].size() + 1);
                    path[i][l].insert(path[i][l].end(),
                            path[i][midium].begin(), path[i][midium].end());
                    path[i][l].push_back(midium);
                    path[i][l].insert(path[i][l].end(),
                            path[midium][l].begin(), path[midium][l].end());
                }
            }
        }
    }
    
    printCost(cost, n);
    printPath(path, n, cost);

    return 0;
}