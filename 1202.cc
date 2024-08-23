#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

cll MAX_N = 3*1e5, MAX_K = MAX_N;
ll n, k;


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pqpll pq;
    multiset<ll> s;
    cin>>n>>k;
    for(ll m, v, i = 0; i<n; ++i)
    {
        cin>>m>>v;
        pq.push(make_pair(v, m));
    }
    for(ll c, i = 1; i<=k; ++i)
    {
        cin>>c;
        s.insert(c);
    }
    
    ll result = 0;
    while(!pq.empty())
    {
        ll v = pq.top().first, m = pq.top().second;
        pq.pop();
        auto it = s.lower_bound(m);
        if(it == s.end())
        {
            continue;
        }

        result += v;
        s.erase(it);
    } 
   
    cout<<result<<"\n";

    return 0;
}