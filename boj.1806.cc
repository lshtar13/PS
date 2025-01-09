#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll n, s;
    scanf("%lld %lld", &n, &s);

    vector<ll> nums(n);
    for(ll i = 0; i<n; ++i)
    {
        scanf("%lld", &nums[i]);
    }

    ll sum = 0, fp = -1, rp = 0, result = 0;
    while(true)
    {
        if(sum < s)
        {
            if(++fp >= n)
            {
                break;
            }
            sum += nums[fp];
        }
        else
        {
            sum -= nums[rp++];
        }

        if(sum >= s)
        {
            result = min(result ? result : LLONG_MAX, fp - rp + 1);
        }
    }

    printf("%lld", result);

    return 0;
}