#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll n;
    scanf("%lld", &n);

    ll result = 0;
    for (ll i = 1; i * i <= n; ++i)
        ++result;

    printf("%lld", result);
    return 0;
}