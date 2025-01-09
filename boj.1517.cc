#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX_N = 5e5;
ll n, result = 0, nums[MAX_N] = {0}, sorted[MAX_N] = {0};

void merge(ll s, ll e)
{
    ll mid = (s+e)/2, i = s, j = mid + 1, k = s;
    while(i<=mid && j<=e)
    {
        if(nums[i] <= nums[j])
        {
            sorted[k++] = nums[i++];
        }
        else
        {
            sorted[k++] = nums[j++], result += j - k;
        }
    }

    ll l = i>mid?j:i;
    while(k<=e)
    {
        sorted[k++] = nums[l++];
    }

    for(int i = s; i<=e; ++i)
    {
        nums[i] = sorted[i];
    }
}

void mergeSort(ll s, ll e)
{
    if(s<e)
    {
        ll mid = (s+e)/2;
        mergeSort(s,mid);
        mergeSort(mid+1,e);
        merge(s,e);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n; 
    for(ll i = 0; i<n; ++i)
    {
        cin>>nums[i];
    }
    mergeSort(0,n-1);
    cout<<result;

    return 0;
}