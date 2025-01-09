#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    scanf("%d", &n);

    int d[20][20];
    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<n; ++l)
        {
            scanf("%d", &d[i][l]);
        }
    }

    const int MAX_COST = 20 * 10000 + 1;
    int cases = 1<<n; 
    int cost[1<<20] = {0}, status[1<<20] = {0};

    for(int i = 1; i<cases; ++i)
    {
        cost[i] = MAX_COST;
        for(int toRemove = 0; toRemove<n; ++toRemove)
        {
            if(!(i&(1<<toRemove)))
            {
                continue;
            }
            int tgt = i & (~(1<<toRemove)), tgtStatus = status[tgt], 
                minTgtCost = MAX_COST, minTgtStatus;
            for(int job = 0; job<n; ++job)
            {
                if((tgtStatus&(1<<job)))
                {
                    continue;
                }

                if(minTgtCost > d[toRemove][job])
                {
                    minTgtCost = d[toRemove][job];
                    minTgtStatus = tgtStatus|(1<<job);
                }
            }

            if(cost[tgt] + minTgtCost < cost[i])
            {
                cost[i] = cost[tgt] + minTgtCost;
                status[i] = minTgtStatus;
            }
        }
    }

    printf("%d", cost[cases-1]);
    
    return 0;
}