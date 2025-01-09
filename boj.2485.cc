#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll gcd(ll n, ll m)
{
    if (n == 0)
        return m;
    return gcd(m % n, n);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    ll first, second, pre, GCD, gaps[100000];
    scanf("%lld %lld", &first, &second);
    gaps[0] = second - first, pre = second, GCD = gaps[0];
    for (ll i = 2, x, gap; i < n; ++i)
    {
        scanf("%lld", &x);
        gaps[i - 1] = gap = x - pre;
        GCD = gcd(min(GCD, gap), max(GCD, gap)), pre = x;
    }

    int result = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        result += gaps[i] / GCD - 1;
    }

    printf("%d", result);

    return 0;
}