#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, m;
    cin>>n>>m;

    vector<pair<ll, ll>> backers;
    for(ll s, e, i = 1; i<=n; ++i)
    {
        cin>>s>>e;
        if(s>e) //backer
        {
            backers.push_back(make_pair(s, 2*i));
            backers.push_back(make_pair(e, 2*i+1));
        }
    }

    sort(backers.begin(), backers.end());
    ll result = m, start = -1, cnt = 0;
    for (auto backer: backers)
    {
        ll pos = backer.first, idx = backer.second/2;
        bool isStart = backer.second%2;

        if(isStart)
        {
            if(!cnt)
            {
                start = pos;
            }
            cnt += idx;
        }
        else
        {
            cnt -= idx;
            if(!cnt)
            {
                result += 2*(pos - start);
            }
        }
    }
    
    cout<<result;

    return 0;
}