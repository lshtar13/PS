#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define INF 987654321

int main(void)
{
    int v, e;
    scanf("%d %d", &v, &e);
    vector<vector<int>> cost(v, vector<int>(v, INF));
    for(int i = 0; i<v; ++i)
    {
        cost[i][i] = 0;
    }

    for(int i = 0, a, b, c; i<e; ++i)
    {
       scanf("%d %d %d", &a, &b, &c);
       cost[a][b] = min(cost[--a][--b], c);
    }

    for(int midium = 0; midium<v; ++midium)
    {
        for(int i = 0; i<v; ++i)
        {
            for(int l = 0; l<v; ++l)
            {
                cost[i][l] = min(cost[i][l],
                                cost[i][midium]+cost[midium][l]);
            }
        }
    }

    int result = INF;
    for(int i = 0; i<v; ++i)
    {
        for(int l = 0; l<v; ++l)
        {
            if(i == l)
            {
                continue;
            }

            if(cost[i][l] != INF && cost[l][i]!=INF)
            {
                result = min(result, cost[i][l] + cost[l][i]);
            }
        }
    }

    printf("%d", result != INF?result:-1);
    return 0;
}