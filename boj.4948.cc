#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    vector<bool> isprime(246913, true);
    isprime[1] = false;
    for (int i = 2; i <= 246912; ++i)
    {
        if (!isprime[i])
            continue;

        for (int l = i + i; l <= 246912; l += i)
            isprime[l] = false;
    }

    while (true)
    {
        int n;
        scanf("%d", &n);

        if (n == 0)
            break;

        int result = 0;
        for (int i = n + 1; i <= 2 * n; ++i)
            if (isprime[i])
                ++result;

        printf("%d\n", result);
    }

    return 0;
}