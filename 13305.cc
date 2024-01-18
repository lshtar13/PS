#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main(void)
{
    int n;
    scanf("%d", &n);

    ll cities[100000], roads[100000];
    for (int i = 0; i < n - 1; ++i)
        scanf("%lld", &roads[i]);
    for (int i = 0; i < n; ++i)
        scanf("%lld", &cities[i]);

    ll minprice = cities[0], result = 0;
    for (int i = 1; i < n; ++i)
    {
        result += minprice * roads[i - 1];
        minprice = min(minprice, cities[i]);
    }
    printf("%lld", result);

    return 0;
}