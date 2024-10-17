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
typedef vector<vll> vvll;

cll N = 50000, MAX_CAR = N / 3;
ll n, preSum[N + 1] = {}, dp[N + 1][4] = {{}}, maxCar;

ll search(ll idx, ll cnt)
{
    if (cnt == 0 || idx >= n)
    {
        return 0;
    }
    else if (dp[idx][cnt])
    {
        return dp[idx][cnt];
    }

    dp[idx][cnt] = search(idx + 1, cnt);
    dp[idx][cnt] = max(dp[idx][cnt], preSum[idx + min(maxCar, n - idx)] - preSum[idx] + search(idx + maxCar, cnt - 1));

    return dp[idx][cnt];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> preSum[i];
        preSum[i] += preSum[i - 1];
    }
    cin >> maxCar;

    cout << search(0, 3) << "\n";

    return 0;
}