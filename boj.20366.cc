#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, snows[600] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i = 0; i<n; ++i)
    {
        cin>>snows[i];
    }
    sort(snows, snows + n);

    ll result = 1e9;
    for(ll s = 0; s<n; ++s)
    {
        for(ll e = s+3; e<n; ++e)
        {
            ll st = s+1, en = e-1, sum0 = snows[s] + snows[e], sum1;
            while(st<en)
            {
                // cout<<s<<" "<<e<<" "<<st<<" "<<en<<"\n";
                sum1 = snows[st] + snows[en];
                result = min(result, abs(sum0 - sum1));
                if(sum0 < sum1)
                {
                    --en;
                }
                else if(sum0 > sum1)
                {
                    ++st;
                }
                else
                {
                    break;
                }
            }
        }
    }

    cout<<result<<"\n";

    return 0;
}