#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    double a;
    ull b, x, y = 1e9;

    cin>>a>>b;
    x = a * y;
    for(ull _x = x, _y = y, i = 0; i<b; ++i)
    {
        x *= _x, y *= _y;
    }

    cout<<double(x)/double(y)<<"\n";

    return 0;
}