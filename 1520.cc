#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, n, mat[500*500], dp[500*500];

int dfs(int start)
{
    if(dp[start] != -1)
    {
        return dp[start];
    }

    dp[start] = 0;
    int i = start/n, j = start%n, next;
    if(i+1<m && mat[next = (i+1)*n+j] < mat[start])
    {
        dp[start] += dfs(next);
    }
    if(i-1>=0 && mat[next = (i-1)*n+j] < mat[start])
    {
        dp[start] += dfs(next);
    }
    if(j+1<n && mat[next = i*n+j+1] < mat[start])
    {
        dp[start] += dfs(next);
    }
    if(j-1>=0 && mat[next = i*n+j-1] < mat[start])
    {
        dp[start] += dfs(next);
    }

    return dp[start];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin>>m>>n;
    for(int i = 0; i<m; ++i)
    {
        for(int j = 0; j<n; ++j)
        {
            cin>>mat[i*n + j];
        }
    }

    dp[n*m-1] = 1;
    cout<<dfs(0);
    return 0;
}