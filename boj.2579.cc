#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int stair[301][2] = {{0, 0}};

    int n;
    scanf("%d", &n);

    scanf("%d", &stair[1][0]);
    stair[1][1] = stair[1][0];
    for (int score, i = 2; i <= n; ++i)
    {
        scanf("%d", &score);
        stair[i][0] = stair[i - 1][1] + score;
        stair[i][1] = max(stair[i - 2][0], stair[i - 2][1]) + score;
    }

    printf("%d", max(stair[n][0], stair[n][1]));
    return 0;
}