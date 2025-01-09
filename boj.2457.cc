#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;

cll MAX_FLOWER = 1e5, calendar[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365},
    START_DATE = calendar[3] + 1, END_DATE = calendar[11] + 30;
ll n, date, idx, result;
pll flowers[MAX_FLOWER] = {make_pair(0, 0)};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(ll st_month, st_day, en_month, en_day, i = 0; i<n; ++i)
    {
        cin>>st_month>>st_day>>en_month>>en_day;
        flowers[i] = make_pair(calendar[st_month]+st_day, calendar[en_month]+en_day);
    }
    sort(flowers, flowers+n);

    result = 0, date = START_DATE, idx = 0;
    for(ll buf, _date = date, _idx = idx; date<=END_DATE; 
        _idx = ++idx, ++result, date = _date)
    {
        cin>>buf;
        for(;_idx<n && flowers[_idx].first<=date; ++_idx)
        {
            if(_date < flowers[_idx].second)
            {
                _date = flowers[_idx].second, idx = _idx;
            }
        }

        if(flowers[idx].first>date)
        {
            result = 0;
            break; 
        }
    }

    cout<<result<<"\n";

    return 0;
}