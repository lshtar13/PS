#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
    
int dp[2000][2000] = {{0}};
int n, m, nums[2000] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; ++i)
    {
        cin>>nums[i];
        dp[i][i] = true;
    }

    for(int term = 1; term < n; ++term)
    {
        for(int start = 0, end = start + term; end < n; end = ++start + term)
        {
            int inside = 1; 
            if(start+1 <= end-1)
            {
                inside = dp[start + 1][end - 1];
            }

            dp[start][end] = inside && (nums[start] == nums[end]);
        }
    }

    cin>>m;

    for(int s, e, i = 0; i<m; ++i)
    {
        cin>>s>>e;
        cout<<dp[--s][--e]<<"\n";
    }

    return 0;
}