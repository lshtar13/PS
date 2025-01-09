#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, wine[10001][2], result = 0;
    scanf("%d %d", &n, &wine[1][0]);
    wine[1][1] = wine[1][0], wine[0][0] = wine[0][1] = 0;

    if (n >= 2)
    {
        scanf("%d", &wine[2][0]);
        wine[2][1] = wine[1][1] + wine[2][0];
    }

    for (int i = 3; i <= n; ++i)
    {
        scanf("%d", &wine[i][0]);
        wine[i][1] = max(wine[i][0] + wine[i - 2][1], max(wine[i][0] + wine[i - 1][0] + wine[i - 3][1], wine[i - 1][1]));
        // printf("i:%d %d %d\n", i, wine[i][0], wine[i][1]);
    }

    printf("%d", wine[n][1]);
    return 0;
}