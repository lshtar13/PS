#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int result = 1, n, a[1001][3];
    scanf("%d %d", &n, &a[1][0]);
    a[1][2] = a[1][1] = 1;
    for (int l, i = 2; i <= n; ++i)
    {
        scanf("%d", &a[i][0]);
        for (a[i][1] = 1, l = 1; l < i; ++l)
            if (a[l][0] < a[i][0])
                a[i][1] = max(a[i][1], a[l][1] + 1);
        for (a[i][2] = a[i][1], l = 1; l < i; ++l)
            if (a[l][0] > a[i][0])
                a[i][2] = max(a[i][2], a[l][2] + 1);
        result = max(result, a[i][2]);
        // printf("%d : %d\n", i, a[i][1]);
    }

    printf("%d", result);
    return 0;
}