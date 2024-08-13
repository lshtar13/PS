#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n, m, sum = 0, scan[100000] = {0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(ll i = 0; i<n; ++i)
    {
        cin>>scan[i];
        sum += scan[i];
    }
    sort(scan, scan+n);

    ll left = 1, right = sum * (m/n + (m%n?1:0));
    while(left<right)
    {
        ll mid = (left + right)/2, scanSum = 0;
        for(ll i = 0; i<n; ++i)
        {
            scanSum += mid/scan[i];
        }

        // cout<<left<<" "<<right<<" "<<scanSum<<"\n";

        if(scanSum<m)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    cout<<left;

    return 0;
}