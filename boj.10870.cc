#include <bits/stdc++.h>

using namespace std;

long long cache[21] = {0, 1, 1, 2};

long long fibo(int n)
{
    if (cache[n] || n == 0)
        return cache[n];
    else
        return cache[n] = fibo(n - 1) + fibo(n - 2);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%lld", fibo(n));
    return 0;
}