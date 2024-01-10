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
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int A = a * d + b * c, B = b * d;
    int GCD = gcd(min(A, B), max(A, B));
    printf("%d %d", A / GCD, B / GCD);
    return 0;
}