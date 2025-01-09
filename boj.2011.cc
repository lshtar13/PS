#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    const ll MOD_MAX = 1e6;
    ll length, dp[5001] = {0};
    char cyper[5001] = {0};
    cin>>cyper;
    length = strlen(cyper);

    dp[length - 1] = cyper[length - 1] - '0' ? 1 : 0, dp[length] = 1;
    // cout<<dp[length - 1]<<"\n";
    for(ll idx = length - 2; idx>=0; --idx)
    {
        short c = 0;
        //case 0
        c = cyper[idx]  - '0';
        if(c>0 && c<10)
        {
            dp[idx] = (dp[idx] + dp[idx + 1])%MOD_MAX;
        }
        //case 1

        c = cyper[idx+1] - '0' + 10 * (cyper[idx] - '0');
        if(c>=10 && c<=26)
        {
            dp[idx] = (dp[idx] + dp[idx + 2])%MOD_MAX;
        }

        // cout<<dp[idx]<<"\n";
    }

    cout<<dp[0]<<"\n";

    return 0;
}