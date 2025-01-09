#include <bits/stdc++.h>

using namespace std;

long long cache[21] = {1, 1, 2};

long long fact(int n)
{
    if (cache[n])
        return cache[n];
    else
        return cache[n] = fact(n - 1) * n;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%lld", fact(n));
    return 0;
}