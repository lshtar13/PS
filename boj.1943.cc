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

cll MAX_PRICE = 5e4;

bool solve(ll n)
{
    ll sum = 0, dp[MAX_PRICE + 1] = {};

    dp[0] = 1;
    for (ll a, b, i = 0; i < n; ++i)
    {
        cin >> a >> b;
        sum += a * b;
        for (ll l = min(sum, MAX_PRICE); l >= 0; --l)
        {
            for (ll j = 0; dp[l] && l + j * a <= min(sum, MAX_PRICE) && j <= b; ++j)
            {
                dp[l + j * a] = 1;
            }
        }
    }

    return sum % 2 ? 0 : dp[sum / 2];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    while (cin >> n)
    {
        cout << solve(n) << "\n";
    }

    return 0;
}