#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_CASES = 1e9+3;
const int MAX_CLR = 1001;
int n, k, dp[MAX_CLR][MAX_CLR], dum;
// dp[i][j] ==> i번째 부터 j개 선택할 수 있는 경우의 수;

int fill(int i, int j)
{
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(j == 0)
    {
        return dp[i][j] = 1;
    }

    int result = 0;
    for(int next = i+2; next<n; ++next)
    {
        result = (result + fill(next, j-1))%MAX_CASES;
    }

    return dp[i][j] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<MAX_CLR; ++i)
    {
        memset(dp[i], -1, sizeof(dp[i]));
    }

    cin>>n>>k;
    int result = 0;
    for(int start = 1; start<n; ++start)
    {
        result = (result + fill(start, k-1))%MAX_CASES;
    }
    
    for(int i = 0; i<MAX_CLR; ++i)
    {
        memset(dp[i], -1, sizeof(dp[i]));
    }

    n -= 1;
    result = (result + fill(0, k-1))%MAX_CASES;
    cout<<result;
    // cout<<fill(start = 1, k-1);

    return 0;
}