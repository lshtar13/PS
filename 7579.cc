#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, size[101], cost[101], dp[101][];

    cin>>n>>m;
    for(int i = 0; i<n; ++i)
    {
        cin>>size[i];
    }
    
    for(int i = 0; i<n; ++i)
    {
        cin>>cost[i];
    }

    dp[0][0] = 0;
    for(int i = 1, totalSize = size[i-1], totalCost = cost[i-1];
        i<=n; totalSize += size[i],totalCost += cost[i++])
    {
        int m0 = min(totalSize, m);
        for(int l = 0; l <= m0; ++l)
        {
            if(totalSize - size[i]<l)
            {
                if(l >= size[i])
                {
                    dp[i][l] = dp[i-1][l-size[i]] + cost[i];
                }
                else
                {
                    dp[i][l] = cost[i];
                }
            }
            else
            {
                dp[i][l] = min(dp[i-1][l], dp[i-1][l-size[i]]+cost[i]);
            }
        }
    }

    cout<<dp[n][m];

    return 0;
}