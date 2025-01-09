#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, scale[1001] = {0}, upscale[1001] = {1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(int i = 1; i<=n; ++i)
    {
        cin>>scale[i];
    }
    sort(scale, scale+n+1);

    ll i, result = 1;
    for(i = 1; i<=n; ++i)
    {
        if(scale[i] > result)
        {
            break;
        }
        else
        {
            result += scale[i];
        }
    }
    cout<<result<<"\n";

    return 0;
}