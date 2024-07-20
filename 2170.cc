#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<pair<ll, ll>> map(2*n);
    for(int x,y,i = 1; i<=n; ++i)
    {
        cin>>x>>y;
        map[2*(i-1)+1] = make_pair(x, 2*i + 1);
        map[2*(i-1)] = make_pair(y, 2*i);
    }
    sort(map.begin(), map.end());

    ll result = 0, start = 0, end = 0, cnt =  0;
    for(int i = 0; i<2*n; ++i)
    {
        ll pos = map[i].first, idx = map[i].second/2;
        bool isStart = map[i].second%2;

        if(isStart)
        {
            if(!cnt)
            {
                start = pos;
                // cout<<"start : "<<start<<"\n";
            }
            cnt += idx;
        }
        else
        {
            cnt -= idx;
            if(!cnt)
            {
                // cout<<"end : "<<pos<<"\n";
                result += pos - start;
            }
        }
    }

    cout<<result;

    return 0;
}