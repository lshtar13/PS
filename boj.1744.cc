#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, nums[50] = {0};
    cin>>n;
    for(int i = 0; i<n; ++i)
    {
        cin>>nums[i];
    }
    sort(nums, nums+n);

    ll i = 0, sum = 0, nSum = 0, pSum = 0;
    for(; nums[i] <= 0 && i<n; ++i)
    {
        if(i%2 == 0 && nums[i+1]<=0)
        {
            nSum += nums[i]*nums[i+1];
        }
    }

    if(i>0 && i<=n && nums[i-1]<0 && (i-1)%2 == 0)
    {
        nSum += nums[i-1];
    }

    if(i<n && i%2 == (n-1)%2)
    {
        pSum += nums[i++];
    }

    for(i; i<n-1; ++i)
    {
        if(i%2 != (n-1)%2)
        {
            pSum += nums[i] == 1 ? nums[i] + nums[i+1] : nums[i]*nums[i+1];
        }
    }

    cout<<nSum + pSum<<"\n";

    return 0;
}