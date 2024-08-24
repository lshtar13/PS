#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

ll n, m, ps[100001] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    multiset<pll> s;
    cin>>n;
    for(ll p, l, i = 0; i<n; ++i)
    {
        cin>>p>>l;
        s.insert(make_pair(l, p));
        ps[p] = l;
    }

    cin>>m;
    cin.ignore();
    for(ll p, l, i = 0; i<m; ++i)
    {
        string _input, cmd;
        getline(cin, _input);
        stringstream input(_input);
        input>>cmd;
        if(cmd == "recommend")
        {
            ll x;
            input>>x;
            if(x>0)
            {
                cout<<s.rbegin()->second<<"\n";
            }
            else
            {
                cout<<s.begin()->second<<"\n";
            }
        }
        else if(cmd == "add")
        {
            input>>p>>l;
            s.insert(make_pair(l, p));
            ps[p] = l;
        }
        else
        {
            input>>p;
            l = ps[p];
            s.erase(make_pair(l, p));
            ps[p] = 0;
        }
    }

    return 0;
}