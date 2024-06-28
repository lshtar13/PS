#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<int[2]> dp(n);
    vector<int[2]> lis(n);

    // int dp[][3] = {{0,0}}; // num, pre (for backtrack)
    for(int i = 0, num; i<n; ++i)
    {
        scanf("%d", &dp[i][0]);
    }

    lis.push_back(dp[0][0]);
    dp[0][1] = -1;

    for(int i = 1, num, start, end, mid; i<n; ++i)
    {
        num = dp[i][0], start = 0, end = lis.size()-1;
        for(mid = (start+end)/2; start<=end; mid = (start+end)/2)
        {
            if(lis[mid][0]>num)
        }
    }

    return 0;
}