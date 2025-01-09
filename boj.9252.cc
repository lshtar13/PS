#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int dp[1001][1001] = {{0}}; // length, idx0, idx1, char
    vector<vector<pair<int, int>>> pre(1001,vector<pair<int, int>>(1001, make_pair(0,0)));
    char lcs[1001][1001] = {{0}};
    char s0[1001] = {0}, s1[1001] = {0};
    scanf("%s", s0);
    scanf("%s", s1);
    int len0 = strlen(s0), len1 = strlen(s1);

    for(int i = 1; i<=len0; ++i)
    {
        for(int l = 1; l<=len1; ++l)
        {
            if(s0[i-1] != s1[l-1])
            {
                if(dp[i-1][l]>dp[i][l-1])
                {
                    dp[i][l] = dp[i-1][l];
                    pre[i][l] = make_pair(i-1, l);
                }
                else
                {
                    dp[i][l] = dp[i][l-1];
                    pre[i][l] = make_pair(i, l-1);
                }
            }
            else
            {
                if(dp[i-1][l] > dp[i-1][l-1] + 1)
                {
                    dp[i][l] = dp[i-1][l];
                    pre[i][l] = make_pair(i-1, l);
                }
                else
                {
                    dp[i][l] = dp[i-1][l-1] + 1;
                    pre[i][l] = make_pair(i-1, l-1);
                    lcs[i][l] = s0[i-1];
                }
            }
        }
    }

    string result;
    for(int i = len0, l = len1; i>0 && l>0;)
    {
        if(lcs[i][l])
        {
            result += lcs[i][l];
        }
        int _i = pre[i][l].first, _l = pre[i][l].second;
        i = _i, l = _l;
    }
    reverse(result.begin(), result.end());

    printf("%d\n", dp[len0][len1]);
    printf("%s\n", result.c_str());
    return 0;
}