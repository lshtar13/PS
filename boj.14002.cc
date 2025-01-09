#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    scanf("%d", &n);

    int dp[1000][3] = {{0,0,0}}; // num, pre (for backtrack), length
    for(int i = 0, num; i<n; ++i)
    {
        scanf("%d", &dp[i][0]);
    }

    int result = n-1;
    dp[n-1][1] = -1, dp[n-1][2] = 1;
    for(int i = n-2, num, pre; i >= 0; --i) 
    {
        num = dp[i][0], pre = i;
        for(int l = i+1; l<n; ++l)
        {
            if(dp[l][0] > dp[i][0] && dp[l][2] >= dp[pre][2])
            {
                pre = l;
            }
        }

        if(pre == i)
        {
            dp[i][1] = -1, dp[i][2] = 1;
        }
        else
        {
            dp[i][1] = pre, dp[i][2] = dp[pre][2] + 1;
        }

        if(dp[i][2] >= dp[result][2])
        {
            result = i;
        }
    }

    printf("%d\n", dp[result][2]);
    while(true)
    {
        printf("%d ", dp[result][0]);
        if(dp[result][1] == -1)
        {
            break;
        }
        result = dp[result][1];
    }

    // printf("\n\n");

    // for(int i = 0; i<n; ++i) {
    //     printf("%d ", dp[i][1]);
    // }
    // printf("\n");
    // for(int i = 0; i<n; ++i)
    // {
    //     printf("%d ", dp[i][2]);
    // }

    return 0;
}