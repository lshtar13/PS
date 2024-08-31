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

ll l, k, c, maxLength, length[10001] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>l>>k>>c;
    ++c;
    set<ll> s;
    for(ll spot, st = 0, i = 0; i<k; ++i)
    {
        cin>>spot;
        s.insert(spot);
    }
    k = s.size(), maxLength = 0;
    ll prev = 0, i = 0;
    for(auto &spot : s)
    {
        maxLength = max(maxLength, length[i++] = spot - prev), prev = spot;
    }
    if(*s.rbegin() < l)
    {
        length[k++] = l - *s.rbegin();
    }

    ll st, en, mid, sum, _c, result0, result1;
    for(st = 1, en = l, mid = (st + en)/2; st<en; mid = (st+en)/2)
    {
        bool isValid = maxLength<=mid;
        for(sum = 0, _c = 0, i = k-1; isValid && i>=0; --i)
        {
            if((sum += length[i])>mid)
            {
                ++_c, sum = length[i];
            }
        }
        
        if(isValid && _c<=c)
        {
            result0 = mid, result1 = sum, en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }


    cout<<result0<<" "<<result1<<"\n";

    return 0;
}