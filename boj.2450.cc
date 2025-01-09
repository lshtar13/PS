#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, polygon[3] = {0}, type[100000] = {0};

ll count(ll s, ll idx, ll limit, ll c[3][3])
{
    ll s0 = (3-s)%2, s1 = 3-s-s0;
    for(;idx<limit; ++idx)
    {
        if(type[idx] == s0)
        {
            ++c[s][s0];
        }
        else if(type[idx] == s1)
        {
            ++c[s][s1];
        }
    }

    return idx;
}

ll change(ll s[3])
{
    ll idx = 0, c[3][3] = {{0}}, result = 0, _r;
    idx = count(s[0], idx, polygon[s[0]], c);
    idx = count(s[1], idx, polygon[s[0]]+polygon[s[1]], c);
    idx = count(s[2], idx, polygon[s[0]]+polygon[s[1]]+polygon[s[2]], c);

    _r = min(c[0][1], c[1][0]);
    result += _r, c[0][1] -= _r, c[1][0] -= _r;
    _r = min(c[0][2], c[2][0]);
    result += _r, c[0][2] -= _r, c[2][0] -= _r;
    _r = min(c[2][1], c[1][2]);
    result += _r, c[2][1] -= _r, c[1][2] -= _r;

    result += (c[0][1] + c[1][0])*2; 

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 0; i<n; ++i)
    {
        cin>>type[i];
        --type[i];
        for(int s = 0; s<3; ++s)
        {
            if(type[i]==s)
            {
                ++polygon[s];
            }
        }
    }

    ll s[6][3] = {
            {0, 1, 2},
            {0, 2, 1},
            {1, 0, 2},
            {1, 2, 0},
            {2, 0, 1},
            {2, 1, 0}
        }, result = LLONG_MAX;
    for(int i = 0; i<6; ++i)
    {
        result = min(result, change(s[i]));
        // cout<<change(s[i])<<"\n";
    }

    cout<<result<<"\n";

    return 0;
}