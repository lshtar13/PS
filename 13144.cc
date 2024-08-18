#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;

cll MAX_N = 1e5;
ull n, nums[MAX_N] = {0}, state[MAX_N+1] = {0}, st, en;

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

    st = en = 0;
    while(en<=n)
    {
        ++state[nums[++en]];
        while(state[nums[en]]> 1)
        {
            state
        }
    }

    return 0;
}