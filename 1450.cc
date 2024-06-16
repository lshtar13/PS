#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void dfs(ll tgt, const ll end, const vector<ll> &nums, vector<ll> &sums)
{
    static ll sum = 0; 
    if(tgt == end)
    {
        sums.push_back(sum);
        return;
    }

    dfs(tgt+1, end, nums, sums);

    sum += nums[tgt];
    dfs(tgt+1, end, nums, sums);
    sum -= nums[tgt];
}

int main(void)
{
    ll n, c, mid;
    scanf("%lld %lld", &n, &c);
    mid = n/2;

    vector<ll> nums0(mid), nums1(n-mid), sums0, sums1;
    for(int i = 0; i<mid; ++i)
    {
        scanf("%lld", &nums0[i]);
    }
    dfs(0,mid,nums0,sums0);
    for(int i = mid; i < n; ++i)
    {
        scanf("%lld", &nums1[i-mid]);
    }
    dfs(0,n-mid,nums1,sums1);

    sort(sums0.begin(), sums0.end());
    sort(sums1.begin(), sums1.end()), greater<>();

    ll p0 = 0, p1 = 0;
    while(true)
    {
        //herererer
    }

    return 0;
}