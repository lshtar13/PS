#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, cmpnd[5000] = {0};

ll search(ll tgt, ll s, ll e)
{
    ll _s = s, _e = e;
    while(_s<=_e)
    {
        ll mid = (_s+_e)/2;
        if(cmpnd[mid] < tgt)
        {
            _s = mid + 1;
        }
        else
        {
            _e = mid - 1;
        }
    }

    _s = min(e, _s), _e = max(s, _e);
    if(abs(cmpnd[_s]-tgt)<abs(cmpnd[_e]-tgt))
    {
        return _s;
    }
    else
    {
        return _e;
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
        cin>>cmpnd[i];
    }
    sort(cmpnd, cmpnd+n);

    ll result[3] = {cmpnd[0], cmpnd[1], cmpnd[2]},
        resultSum = cmpnd[0] + cmpnd[1] + cmpnd[2];
    for(ll idx0 = 0; idx0 < n-2; ++idx0)
    {
        for(ll idx1 = idx0+1; idx1<n-1; ++idx1)
        {
            ll sum = cmpnd[idx0] + cmpnd[idx1], idx2 = search(-sum, idx1+1, n-1);
            sum += cmpnd[idx2];
            if(abs(resultSum) > abs(sum))
            {
                resultSum = sum;
                result[0] = cmpnd[idx0], result[1] = cmpnd[idx1], result[2] = cmpnd[idx2];
                // cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<" "<<resultSum<<"\n";
            }
        }
    }
    sort(cmpnd, cmpnd+3);

    cout<<result[0]<<" "<<result[1]<<" "<<result[2]<<"\n";

    return 0;
}