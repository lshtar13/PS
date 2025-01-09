#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int sum[500][500];

    int n;
    scanf("%d %d", &n, &sum[0][0]);

    for (int i = 1; i < n; ++i)
        for (int num, l = 0; l <= i; ++l)
        {
            scanf("%d", &num);
            if (l == 0)
                sum[i][l] = sum[i - 1][l] + num;
            else if (l == i)
                sum[i][l] = sum[i - 1][l - 1] + num;
            else
                sum[i][l] = max(sum[i - 1][l - 1], sum[i - 1][l]) + num;

            // printf("%d,%d==>%d\n", i, l, sum[i][l]);
        }

    int result = 0;
    for (int i = 0; i <= n - 1; ++i)
        result = max(result, sum[n - 1][i]);

    printf("%d", result);
    return 0;
}