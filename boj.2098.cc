#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_COST = 0x3f3f3f3f, MAX_STATUS = 1<<16;
int n, w[16][16], dp[16][MAX_STATUS] = {{0}};

int cost(int cur, int status, int start)
{
    if(dp[cur][status])
    {
        return dp[cur][status];
    }

    if(status == (1<<n)-1)
    {
        return dp[cur][status] = w[cur][start]?w[cur][start]:MAX_COST;
    }

    dp[cur][status] = MAX_COST;
    for(int next = 0; next<n; ++next)
    {
        if(!(status & (1<<next)) 
            && w[cur][next])
        {
            dp[cur][status] = min(dp[cur][status], 
                                    w[cur][next] + cost(next,status | (1<<next), start));
        }
    }

    return dp[cur][status];
}

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    scanf("%d", &n);
    for(int i = 0; i<n; ++i)
    {
        for(int j = 0; j<n; ++j)
        {
            scanf("%d", &w[i][j]);
        }
    }

    // fill(&dp[0][0], &dp[15][MAX_STATUS-1], MAX_COST);

    // int result = INT_MAX;
    // for(int i = 0; i<n; ++i)
    // {
    //     printf("%d\n", cost(i, 1<<i, i));
    //     result = min(cost(i, 1<<i, i), result);
    // }
    printf("%d",cost(0,1, 0));
    return 0;
}