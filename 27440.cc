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

unordered_map<ll, ll> dp;
ll n;

ll search(ll k)
{
    if(dp[k])
    {
        return dp[k];
    }
    else if(k == 1)
    {
        return dp[k] = 0;
    }

    ll result = k;
    
    // 이분탐색으로 2와 3으로 최대 절삭 범위 구하기
    
    if(k%3 == 0)
    {
        result = min(result, k/3 + search(k%3));
    }
    if(k%2 == 0)
    {
        result = min(result, k/2 + search(k%2));
    }
    result = min(result, 1+search(k-1));

    return dp[k] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    cout<<search(n)<<"\n";

    return 0;
}