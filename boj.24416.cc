#include <bits/stdc++.h>

using namespace std;

int fib(int n, int &result1)
{
    if (n == 1 || n == 2)
    {
        ++result1;
        return 1;
    }
    else
        return fib(n - 1, result1) + fib(n - 2, result1);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int fibo[41] = {0, 1, 1};

    int result1 = 0, result2 = 0;
    fib(n, result1);
    for (int i = 3; i <= n; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2], ++result2;
    printf("%d %d", result1, result2);
    return 0;
}