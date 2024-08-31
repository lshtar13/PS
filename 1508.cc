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

cll MAX_JUDGE = 50;
ll n, m, k, judge[MAX_JUDGE] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m>>k;
    for(ll i = 0; i<k; ++i)
    {
        cin>>judge[i];
    }

    string ans;
    ll st = 0, en = n;
    while(st<=en)
    {
        string _ans = "1";
        ll mid = (st + en)/2, _m = 1;
        for(ll prev = judge[0], i = 1; i<k && _m<m; ++i)
        {
            if(judge[i] - prev >= mid)
            {
                ++_m, prev = judge[i], _ans += "1";
            }
            else
            {
                _ans += "0";
            }
        }

        for(ll i = _ans.length(); i<k; ++i)
        {
            _ans += "0";
        }

        if(_m==m)
        {
            ans = _ans, st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    cout<<ans<<"\n";
 
    return 0;
}