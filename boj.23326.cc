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

ll n, q;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>q;
    set<ll> us;
    for(ll isFamous, i = 0; i<n; ++i)
    {
        cin>>isFamous;
        if(isFamous)
        {
            us.insert(i);
        }
    }

    for(ll a, b, c = 0; q--;)
    {
        cin>>a;
        switch(a)
        {
            case 1:
            cin>>b;
            --b;
            if(us.find(b) == us.end())
            {
                us.insert(b);
            }
            else
            {
                us.erase(b);
            }
            break;

            case 2:
            cin>>b;
            c = (b+c)%n;
            break;

            case 3:
            auto it = us.lower_bound(c);
            if(it != us.end())
            {
                cout<<*it - c<<"\n";
            }
            else if((it = us.lower_bound(0)) != us.end())
            {
                cout<<n - c + *it<<"\n";
            }
            else
            {
                cout<<-1<<"\n";
            }
            break;
        }
    }

    return 0;
}