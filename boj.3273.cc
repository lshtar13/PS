#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll n;
    map<ll,ll> hash;
    scanf("%lld", &n);
    vector<ll> nums0(n), nums1(n);
    for(ll i = 0; i<n; ++i)
    {
        scanf("%lld", &nums0[i]);
        hash[nums0[i]] = i, nums1[i] = nums0[i];
    }
    sort(nums0.begin(), nums0.end());
    sort(nums1.begin(), nums1.end(), greater<>());

    ll x, p0 = 0, p1 = 0, result = 0;
    scanf("%lld", &x);

    while(p0<n && p1<n)
    {
        if(nums0[p0] + nums1[p1] <= x )
        {
            if(nums0[p0] + nums1[p1] == x
                && hash[nums0[p0]] > hash[nums1[p1]])
            {
                ++result;   
            }
            ++p0;
        }
        else
        {
            ++p1;
        }
    }

    printf("%lld", result);

    return 0;
}