// 복습 요망

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char s0[1001], s1[1001];
    int dp[1001][1001] = {0};
    scanf("%s %s", s0, s1);

    for (int len0 = strlen(s0), i = 1; i <= len0; ++i)
        for (int len1 = strlen(s1), l = 1; l <= len1; ++l)
            if (s0[i - 1] == s1[l - 1])
                dp[i][l] = dp[i - 1][l - 1] + 1;
            else
                dp[i][l] = max(dp[i - 1][l], dp[i][l - 1]);

    printf("%d", dp[strlen(s0)][strlen(s1)]);
    return 0;
}