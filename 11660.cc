#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m, num, col[1025][1025] = {0};
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; ++i)
        for (int l = 1; l <= n; ++l)
        {
            scanf("%d", &num);
            col[i][l] = col[i][l - 1] + num;
        }

    for (int x1, y1, x2, y2, i = 0; i < m; ++i)
    {
        int sum = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = x1; i <= x2; ++i)
            sum += col[i][y2] - col[i][y1 - 1];
        printf("%d\n", sum);
    }
    return 0;
}