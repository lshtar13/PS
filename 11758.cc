#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll x0, y0, x1, y1, x2, y2;
    cin>>x0>>y0>>x1>>y1>>x2>>y2;
    ll ccw = x0*y1+x1*y2+x2*y0 - (y0*x1+y1*x2+y2*x0);
    if(ccw<0)
    {
        cout<<-1;
    }
    else if(ccw>0)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }

    return 0;
}