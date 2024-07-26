#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, dp[110][220] = {{0}};
const int ONE_DAY = 0, THREE_DAY = 1, FIVE_DAY = 2, COUPON = 3,
            tickets[4] = {ONE_DAY, THREE_DAY, FIVE_DAY, COUPON},
            price[4] = {10, 25, 37, 0}, days[4] = {1, 3, 5, 1},
            coupons[4] = {0, 1, 2, 0}, consume[4] = {0, 0, 0, 3};
bool isInvalid[110] = {false};

int cost(int day, int nCoupon)
{
    if(day >= n)
    {
        return 0;
    }
    else if(dp[day][nCoupon]!=INT_MAX)
    {
        return dp[day][nCoupon];
    }
    else if(isInvalid[day])
    {
        return dp[day][nCoupon] = cost(day+1, nCoupon);
    }
    
    for(auto ticket: tickets)
    {
        if(nCoupon < consume[ticket])
        {
            continue;
        }
        dp[day][nCoupon]= min(dp[day][nCoupon], price[ticket] + cost(day + days[ticket], 
                                    nCoupon + coupons[ticket] - consume[ticket]));
    }

    return dp[day][nCoupon];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i<110; ++i)
    {
        for(int j = 0; j<220; ++j)
        {
            dp[i][j] = INT_MAX;
        }
    }

    cin>>n>>m;
    for(int day, i = 0; i<m; ++i)
    {
        cin>>day;
        isInvalid[--day] = true;
    }
    cout<<cost(0,0)*1000<<"\n";

    return 0;
}