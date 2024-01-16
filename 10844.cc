#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, e9 = int(1e9);
    scanf("%d", &n);

    int result[101][10];
    result[1][0] = 0;
    for (int i = 1; i < 10; ++i)
        result[1][i] = 1;

    for (int i = 2; i <= n; ++i)
    {
        result[i][0] = result[i - 1][1] % e9;
        result[i][1] = (result[i - 1][0] + result[i - 1][2]) % e9;
        result[i][2] = (result[i - 1][1] + result[i - 1][3]) % e9;
        result[i][3] = (result[i - 1][2] + result[i - 1][4]) % e9;
        result[i][4] = (result[i - 1][3] + result[i - 1][5]) % e9;
        result[i][5] = (result[i - 1][4] + result[i - 1][6]) % e9;
        result[i][6] = (result[i - 1][5] + result[i - 1][7]) % e9;
        result[i][7] = (result[i - 1][6] + result[i - 1][8]) % e9;
        result[i][8] = (result[i - 1][7] + result[i - 1][9]) % e9;
        result[i][9] = result[i - 1][8] % e9;
    }

    int sum = 0;
    for (int i = 0; i < 10; ++i)
        sum = (sum + result[n][i]) % e9;
    printf("%d", sum);
    return 0;
}