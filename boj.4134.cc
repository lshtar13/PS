#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n;
    scanf("%d", &n);
    for (ll i = 0, num; i < n; ++i)
    {
        scanf("%lld", &num);
        if (num <= 1)
        {
            printf("%d\n", 2);
            continue;
        }

        for (ll k = num;; ++k)
        {
            bool prime = true;
            for (ll l = 2; l * l <= k && prime; ++l)
                if (k % l == 0)
                    prime = false;
            if (prime)
            {
                printf("%lld\n", k);
                break;
            }
        }
    }
    return 0;
}