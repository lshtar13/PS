#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ull MAX_COSTUMER = 1e6;
ull n, k, purchase[MAX_COSTUMER+1] = {0};
pair<ull, ull> results[100000];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>k;
    priority_queue<pair<ull, ull>, vector<pair<ull, ull>>, greater<pair<ull, ull>>> pq;
    for(int i = 0; i<k; ++i)
    {
        pq.push(make_pair(0, i));
    }

    for(ull id, w, cntr, avail_t, i = 0; i<n; ++i)
    {
        cin>>id>>w;
        cntr = pq.top().second, avail_t = pq.top().first+w;
        pq.pop();
        pq.push(make_pair(avail_t, cntr));
        results[i].first = avail_t*2000000 + (100000 - cntr), results[i].second = id;
        // cout<<avail_t<<"\n";
    }
    sort(results, results+n);
    ull result = 0;
    for(int i = 0; i<n; ++i)
    {
        result += (i+1)*(results[i].second);
    }
    cout<<result;

    return 0;
}