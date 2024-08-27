#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef vector<pll> vpll;
typedef const ll cll;
typedef queue<ll> qll;
typedef queue<pll> qpll;
typedef priority_queue<ll> pqll;
typedef priority_queue<ll, vll, greater<ll>> pqgll;
typedef priority_queue<pll> pqpll;
typedef priority_queue<pll, vpll, greater<pll>> pqgpll;

cll MAX_N = 1e5;
ll n, a[MAX_N] = {}, b[MAX_N] = {};
pll gifts[MAX_N] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(ll i = 0; i<n; ++i)
    {
        cin>>gifts[i].second;
    }
    for(ll i = 0; i<n; ++i)
    {
        cin>>gifts[i].first;
    }
    sort(gifts, gifts+n);

    ll result = 0;
    for(ll _c = 0, c = 0, i = 0; i<n; ++i)
    {
        c = max(c, gifts[i].first);
        if(gifts[i].second< c)
        {
            result += (c - gifts[i].second)/30 + bool((c - gifts[i].second)%30);
            gifts[i].second+= 30*((c - gifts[i].second)/30 + bool((c - gifts[i].second)%30));
        }
        _c = max(_c, gifts[i].second);
        if(i<n-1 && gifts[i].first<gifts[i+1].first)
        { 
            c = _c; 
        }
    }

    cout<<result<<"\n";

    return 0;
}