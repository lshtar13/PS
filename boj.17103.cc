#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    vector<bool> isprime(1000001, true);
    vector<int> primes;
    isprime[1] = false;
    for (int i = 2; i <= 1000000; ++i)
    {
        if (!isprime[i])
            continue;

        primes.push_back(i);
        for (int l = i + i; l <= 1000000; l += i)
            isprime[l] = false;
    }

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);

        int result = 0;
        for (auto &x : primes)
        {
            if (2 * x > n)
                break;

            if (isprime[n - x])
                ++result;
        }

        printf("%d\n", result);
    }

    return 0;
}