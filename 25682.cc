#include <bits/stdc++.h>

using namespace std;

int wsum[2001][2001] = {{0}}, bsum[2001][2001] = {{0}};
int main(void)
{
    char c;
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; ++i)
    {
        char s[2001];
        scanf("%s", s);
        for (int l = 1; l <= m; ++l)
        {
            c = s[l - 1];
            if (c == 'B')
                wsum[i][l] = wsum[i - 1][l] + wsum[i][l - 1] - wsum[i - 1][l - 1] + ((i + l) % 2 ? 0 : 1),
                bsum[i][l] = bsum[i - 1][l] + bsum[i][l - 1] - bsum[i - 1][l - 1] + ((i + l) % 2 ? 1 : 0);
            else
                wsum[i][l] = wsum[i - 1][l] + wsum[i][l - 1] - wsum[i - 1][l - 1] + ((i + l) % 2 ? 1 : 0),
                bsum[i][l] = bsum[i - 1][l] + bsum[i][l - 1] - bsum[i - 1][l - 1] + ((i + l) % 2 ? 0 : 1);
        }
    }

    // for (int i = 1; i <= n; ++i)
    // {
    //     for (int l = 1; l <= n; ++l)
    //         printf("%d ", bsum[i][l]);
    //     printf("\n");
    // }

    int result = 0x7fffffff, wvalue, bvalue;
    for (int i = k; i <= n; ++i)
        for (int l = k; l <= m; ++l)
        {
            wvalue = wsum[i][l] - wsum[i - k][l] - wsum[i][l - k] + wsum[i - k][l - k],
            bvalue = bsum[i][l] - bsum[i - k][l] - bsum[i][l - k] + bsum[i - k][l - k],
            result = min(result, min(bvalue, wvalue));
            // printf("%d %d\n", i, l);
        }

    printf("%d", result);
    return 0;
}