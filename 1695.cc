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

cll N = 5000;
int n, nums[N] = {}, dp[N][N] = {{}};

ll search(ll st, ll en)
{
    // cout << st << " " << en << "\n";
    if (st >= en)
    {
        return 0;
    }
    else if (dp[st][en] != -1)
    {
        return dp[st][en];
    }

    ll result = LLONG_MAX;
    if (nums[st] == nums[en])
    {
        result = min(result, search(st + 1, en - 1));
    }
    result = min(result, search(st + 1, en) + 1);
    result = min(result, search(st, en - 1) + 1);

    return dp[st][en] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << search(0, n - 1) << "\n";

    return 0;
}