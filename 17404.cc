#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int INF = 1234567;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, cost[1000][3], dp[2][3], result = INF;
    cin>>n;
    for(int i = 0; i<n; ++i)
    {
        cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
    }
    for(int start = 0; start<3; ++start)
    {
        dp[0][start] = cost[0][start];
        dp[0][(start+1)%3] = INF;
        dp[0][(start+2)%3] = INF;

        for(int i = 1; i<n; ++i)
        {
            for(int l = 0; l<3; ++l)
            {
                dp[1][l] = min(dp[0][(l+1)%3], dp[0][(l+2)%3]) + cost[i][l];
            }

            for(int l = 0; l<3; ++l)
            {
                dp[0][l] = dp[1][l];
            }
        }
        
        for(int i = 0; i<3; ++i)
        {
            if(i != start)
            {
                result = min(result, dp[0][i]);
            }
        }
    }

    cout<< result;

    return 0;
}