#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll maxByte = 1e7;
ll n, m, memSum = 0, memLimit,
    mems[100] = {0}, costs[100] = {0}, dp[2][maxByte + 1] = {{0}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    for(ll i = 0; i<n; ++i)
    {
        cin>>mems[i];
        memSum += mems[i];
    }
    for(ll i = 0; i<n; ++i)
    {
        cin>>costs[i];
    }
    memLimit = memSum - m;

    for(ll i = 0, mem = mems[i], cost = costs[i]; i<n; ++i, mem = mems[i], cost = costs[i])
    {       
        for(ll limit = 0; limit<=memLimit; ++limit)
        {
            dp[1][limit] = limit>=mem ? min(dp[0][limit-mem] + cost, dp[0][limit])
                                        :dp[0][limit];
        }
    }

    return 0;
}