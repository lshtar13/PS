#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int house[1000][3];

    int n;
    scanf("%d %d %d %d", &n, &house[0][0], &house[0][1], &house[0][2]);

    for (int r, g, b, i = 1; i < n; ++i)
    {
        scanf("%d %d %d", &r, &g, &b);
        house[i][0] = min(house[i - 1][1], house[i - 1][2]) + r;
        house[i][1] = min(house[i - 1][0], house[i - 1][2]) + g;
        house[i][2] = min(house[i - 1][0], house[i - 1][1]) + b;
    }

    printf("%d", min(min(house[n - 1][0], house[n - 1][1]), house[n - 1][2]));
    return 0;
}