#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef queue<ll> qll;
typedef queue<pll> qpll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;
typedef vector<ll> vll;

cll MAX_N = 1e4;
ll n, p, l;
pll stations[MAX_N+1] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(ll i = 0; i<n; ++i)
    {
        cin>>stations[i].first>>stations[i].second;
    }
    cin>>p>>l;
    stations[n].first = p, stations[n].second = 0;
    sort(stations, stations+n+1);

    ll result = 0;
    pqll pq;
    for(ll i = 0, a = stations[i].first, b = stations[i].second; i<=n;
            ++i, a = stations[i].first, b = stations[i].second)
    {
        // cout<<"l : "<<l<<" "<<a<<"\n";
        while(l<a && !pq.empty())
        {
            l += pq.top(), ++result;
            pq.pop();
        }

        if(l>=a)
        {
            pq.push(b);
        }
        else
        {
            result = -1;
            break;
        }
    }

    cout<<result<<"\n";

    return 0;
}