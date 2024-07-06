#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> point;

// double area(point p0, point p1, point p2)
// {

// }

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
     
    ll n;
    cin>>n;

    // vector<point> polygon(n);
    vector<ll> x(n), y(n);
    for(ll i = 0; i<n; ++i)
    {
       cin>>x[i]>>y[i];
    }

    double result = 0.0; 
    for(ll i = 0; i<n; ++i)
    {
        result += (i != n-1?x[i]*y[i+1]:x[n-1]*y[0]);
        result -= (i != n-1?y[i]*x[i+1]:y[n-1]*x[0]);
    }
    result = abs(result)/2;

    cout<<fixed;
    cout.precision(1);
    cout<<result;
    return 0;
}