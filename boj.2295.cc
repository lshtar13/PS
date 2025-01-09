#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef map<ll, ll> mll;

ll n, nums[1000] = {}, sum0[1000000] = {}, sum1[1000000] = {}, nsum0 = 0, nsum1 = 0;

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

    mll _sum0;
    for(ll i = 0; i<n; ++i)
    {
        for(ll l = i; l<n; ++l)
        {
            _sum0[nums[i]+nums[l]] = 1;
        }
    }

    ll result = 0;
    for(ll i = 0; i<n; ++i)
    {
        for(ll l = 0; l<n; ++l)
        {
            if(_sum0[nums[i]-nums[l]])
            {
                result = max(result, nums[i]);
            }
        }
    }

    cout<<result<<"\n";
    
    return 0;
}