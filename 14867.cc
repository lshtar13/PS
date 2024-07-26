#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MAX_LITER = 1e5;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll literA, literB, finalA, finalB;
    cin>>literA>>literB>>finalA>>finalB;

    map<pair<ll,ll>, ll> visited;
    queue<pair<ll, ll>> q;
    visited[make_pair(0, 0)] = 1;
    q.push(make_pair(0, 0));

    while(!q.empty()) 
    {
        ll a = q.front().first, b = q.front().second, 
            _a, _b, gap, value = visited[make_pair(a, b)];
        q.pop();

        // cout<<a<<" "<<b<<" "<<value<<"\n";

        _a = literA, _b = b;
        if(visited.find(make_pair(_a, _b))==visited.end())
        {
            visited[make_pair(_a, _b)] = value+1;
            q.push(make_pair(_a, _b));
        }

        _a = 0, _b = b;
        if(visited.find(make_pair(_a, _b))==visited.end())
        {
            visited[make_pair(_a, _b)] = value+1;
            q.push(make_pair(_a, _b));
        }

        _a = a+b < literB ? 0 : a+b - literB,
        _b = a+b-_a;
        if(visited.find(make_pair(_a, _b))==visited.end())
        {
            visited[make_pair(_a, _b)] = value+1;
            q.push(make_pair(_a, _b));
        }
    
        _a = a, _b = literB;
        if(visited.find(make_pair(_a, _b))==visited.end())
        {
            visited[make_pair(_a, _b)] = value+1;
            q.push(make_pair(_a, _b));
        }

        _a = a, _b = 0;
        if(visited.find(make_pair(_a, _b))==visited.end())
        {
            visited[make_pair(_a, _b)] = value+1;
            q.push(make_pair(_a, _b));
        }

        _b = a+b < literA ? 0 : a+b - literA,
        _a = a+b-_b;
        if(visited.find(make_pair(_a, _b))==visited.end())
        {
            visited[make_pair(_a, _b)] = value+1;
            q.push(make_pair(_a, _b));
        }
    }
    cout<<visited[make_pair(finalA, finalB)]-1<<"\n";

    return 0;
}