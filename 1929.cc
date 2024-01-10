#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int m, n;
    scanf("%d %d", &m, &n);

    vector<bool> isprime(n + 1, true);
    isprime[1] = false;
    for (int i = 2; i <= n; ++i)
    {
        if (!isprime[i])
            continue;

        for (int l = i + i; l <= n; l += i)
            isprime[l] = false;
    }

    for (int i = m; i <= n; ++i)
        if (isprime[i])
            printf("%d\n", i);

    return 0;
}