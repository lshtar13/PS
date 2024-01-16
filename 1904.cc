#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int binary[1000001] = {0, 1, 2};
    int n;
    scanf("%d", &n);
    for (int i = 3; i <= n; ++i)
        binary[i] = (binary[i - 1] + binary[i - 2]) % 15746;

    printf("%d", binary[n]);
    return 0;
}