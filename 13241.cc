#include <bits/stdc++.h>

using namespace std;

long long int gcd(int n, int m)
{
    if (n == 0)
        return m;
    return gcd(m % n, n);
}

int main(void)
{
    long long int a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld\n", a * b / gcd(min(a, b), max(a, b)));

    return 0;
}