#include <bits/stdc++.h>

using namespace std;

int gcd(int n, int m)
{
    if (n == 0)
        return m;
    return gcd(m % n, n);
}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a * b / gcd(min(a, b), max(a, b)));
    }

    return 0;
}