#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    int sum[100001] = {0};
    for (int x, i = 1; i <= n; ++i)
    {
        scanf("%d", &x);
        sum[i] = sum[i - 1] + x;
    }

    for (int a, b, i = 0; i < m; ++i)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", sum[b] - sum[a - 1]);
    }
    return 0;
}