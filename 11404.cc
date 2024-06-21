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

int main(void)
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    vector<vector<int>> cost(n, vector<int>(n, INF));
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
                cost[i][l] = min(cost[i][l], 
                                cost[i][midium] + cost[midium][l]);
            }
        }
    }
    
    printCost(cost, n);

    return 0;
}