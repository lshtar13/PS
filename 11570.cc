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

cll MAX_N = 2000, MAX_NOTE = 1e6;
ll n, note[MAX_N + 1] = {}, dp[MAX_N + 1][MAX_N + 1] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> note[i];
    }

    // dp[a][b] ==> A가 a번 곡 까지, B가 b번 곡 까지
    dp[0][1] = dp[1][0] = 0;
    for (ll cur = 2; cur <= n; ++cur)
    {
        // A
        for (ll prev = 0; prev < cur - 1; ++prev)
        {
            // note[cur-1] ==> A
            dp[cur][prev] = dp[cur - 1][prev] + abs(note[cur] - note[cur - 1]);
        }
        dp[cur][cur - 1] = MAX_NOTE * MAX_N;
        for (ll gap, prev = 0; prev < cur - 1; ++prev)
        {
            // note[cur-1] ==> B
            gap = prev ? abs(note[cur] - note[prev]) : 0;
            dp[cur][cur - 1] = min(dp[cur][cur - 1], dp[prev][cur - 1] + gap);
        }

        // B
        for (ll prev = 0; prev < cur - 1; ++prev)
        {
            // note[cur-1] ==> B
            dp[prev][cur] = dp[prev][cur - 1] + abs(note[cur] - note[cur - 1]);
        }
        dp[cur - 1][cur] = MAX_NOTE * MAX_N;
        for (ll gap, prev = 0; prev < cur - 1; ++prev)
        {
            // note[cur-1] ==> A
            gap = prev ? abs(note[cur] - note[prev]) : 0;
            dp[cur - 1][cur] = min(dp[cur - 1][cur], dp[cur - 1][prev] + gap);
        }
    }

    ll result = MAX_NOTE * MAX_N;
    for (ll i = 0; i < n; ++i)
    {
        result = min(result, dp[n][i]);
        result = min(result, dp[i][n]);
    }

    cout << result << "\n";

    return 0;
}