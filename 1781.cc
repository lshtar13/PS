#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

ll n;
pqll pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    vector<pll> arr(n, make_pair(0, 0));
    for(int a, b, i = 0; i<n; ++i)
    {
        cin>>arr[i].first>>arr[i].second;
        // arr[i] = make_pair(a, b);
    }
    sort(arr.begin(), arr.end());

    ll result = 0;
    for(ll idx = n-1, tick = n; tick>0; --tick)
    {
        while(idx>=0 && arr[idx].first>=tick)
        {
            pq.push(arr[idx--].second);
        }

        if(!pq.empty())
        {
            result += pq.top();
            pq.pop();
        }
    }

    cout<<result<<"\n";

    return 0;
}
