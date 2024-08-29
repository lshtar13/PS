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

void solve(ll n, ll a, ll b)
{
    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pqA, pqB;
    for(ll k, da, db, i = 0; i<n; ++i)
    {
        cin>>k>>da>>db;
        if(da < db)
        {
            pqA.push(make_pair(da, make_pair(k, db)));
        }
        else
        {
            pqB.push(make_pair(db, make_pair(k, da)));
        }
    }

    ll result = 0;
    while(!pqA.empty())
    {
        ll da = pqA.top().first, k = pqA.top().second.first, db = pqA.top().second.second,
            balloon = min(k, a);
        pqA.pop();
        result += balloon*da, a -= balloon;
        if(balloon < k)
        {
            pqB.push(make_pair(db, make_pair(k - balloon, da)));
        }
    }

    while(!pqB.empty())
    {
        ll db = pqB.top().first, k = pqB.top().second.first, da = pqB.top().second.second,
            balloon = min(k, b);
        pqB.pop();
        result += balloon*db, b -= balloon;
        if(balloon < k)
        {
            pqA.push(make_pair(da, make_pair(k - balloon, db)));
        }
    }
    
    while(!pqA.empty())
    {
        ll da = pqA.top().first, k = pqA.top().second.first, db = pqA.top().second.second,
            balloon = min(k, a);
        pqA.pop();
        result += balloon*da, a -= balloon;
        if(balloon < k)
        {
            pqB.push(make_pair(db, make_pair(k - balloon, da)));
        }
    }

    cout<<result<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(ll n, a, b; cin>>n>>a>>b && (n || a || b);)
    {
        solve(n, a, b);
    }


    return 0;
}