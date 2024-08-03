#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define CORD(x) (x+500000)
ll n, hor[1000001] = {0}, ver[1000001] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    ll prev_x, prev_y, x, y;
    cin>>x>>y;
    prev_x = CORD(x), prev_y = CORD(y);
    for(ll i = 1; i<n; ++i)
    {
        cin>>x>>y;
        x = CORD(x), y = CORD(y);

        if(prev_x == x)
        { // vertical
            ll y0 = min(y, prev_y), y1 = max(y, prev_y);
            ver[x] = -1;
            for(ll _y = y0; _y<=y1; ++_y)
            {
                if(hor[_y]!=-1)
                {
                    ++hor[_y];
                }
            }
        }
        else
        { // horizontal
            ll x0 = min(x, prev_x), x1 = max(x, prev_x);
            hor[y] = -1;
            for(ll _x = x0; _x<=x1; ++_x)
            {
                if(ver[_x]!=-1)
                {
                    ++ver[_x];
                }
            }
        }
        prev_x = x, prev_y = y;
    }

    ll result = 0;
    for(ll i = 0; i<1000001; ++i)
    {
        result = max(result, max(ver[i], hor[i]));
    }
    cout<<result;

    return 0;
}