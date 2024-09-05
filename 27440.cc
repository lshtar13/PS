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

cll N = 1e7;
ll n;
unordered_map<ll, ll> dp;

ll search(ll k)
{
    if (dp[k])
    {
        return dp[k];
    }
    else if (k <= 1)
    {
        return 0;
    }

    return dp[k] = min(search(k / 2) + k % 2, search(k / 3) + k % 3) + 1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << search(n) << "\n";

    return 0;
}