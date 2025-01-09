#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long p[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    for (int i = 11; i <= 100; ++i)
        p[i] = p[i - 1] + p[i - 5];

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", p[n]);
    }
    return 0;
}