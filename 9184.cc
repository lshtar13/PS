#include <bits/stdc++.h>

using namespace std;

int arr[21][21][21] = {{{0}}};

int main(void)
{
    for (int i = 0; i <= 20; ++i)
        for (int j = 0; j <= 20; ++j)
            for (int k = 0; k <= 20; ++k)
            {
                if (i <= 0 || j <= 0 || k <= 0)
                    arr[i][j][k] = 1;
                else if (i < j && j < k)
                    arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
                else
                    arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
            }

    for (int a, b, c; scanf("%d %d %d", &a, &b, &c) && !(a == -1 && b == -1 && c == -1);)
    {
        if (a <= 0 || b <= 0 || c <= 0)
            printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
        else if (a > 20 || b > 20 || c > 20)
            printf("w(%d, %d, %d) = %d\n", a, b, c, arr[20][20][20]);
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, arr[a][b][c]);
    }

    return 0;
}