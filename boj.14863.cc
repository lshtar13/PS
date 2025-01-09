#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[101][100001] = {{0}}, n, k;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    for(int t0, m0, t1, m1, i = 1; i<=n; ++i)
    {
        cin>>t0>>m0>>t1>>m1;
        for(int j = 0; j<=k; ++j)
        {
            dp[i][j] = INT_MIN;
            if(j-t0>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-t0] + m0);
            }

            if(j-t1>=0)
            {
                dp[i][j] = max(dp[i][j], dp[i-1][j-t1] + m1);
            }

            dp[i][j] = dp[i][j]<0?INT_MIN:dp[i][j];
        }
    }

    cout<<dp[n][k];
    return 0;
}