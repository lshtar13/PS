#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    scanf("%d", &n);

    int dp[1000001][2] = {{0,0}};
    for(int i = 2; i<=n; ++i)
    {

        dp[i][0] = INT_MAX;

        if(i%3 == 0 && i/3 > 0 && dp[i/3][0]+1 < dp[i][0])
        {
            dp[i][0] = dp[i/3][0]+1, dp[i][1] = i/3;
        }

        if(i%2 == 0 && i/2 > 0 && dp[i/2][0] + 1 < dp[i][0])
        {
            dp[i][0] = dp[i/2][0] + 1, dp[i][1] = i/2;
        }

        if(i-1 > 0 && dp[i-1][0] + 1 < dp[i][0])
        {
            dp[i][0] = dp[i-1][0] + 1, dp[i][1] = i-1;
        }
    }

    printf("%d\n", dp[n][0]);

    int num = n; 
    while(num >= 1)
    {
        printf("%d ", num);
        num = dp[num][1];
    }
    return 0;
}