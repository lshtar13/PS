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

cll MAX_N = 5e5, MAX_S = 1e3;
ll n, k, prv, sum[MAX_S] = {};
char dp[2][MAX_N + 1] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll i = 1; i < MAX_S; ++i)
    {
        sum[i] = sum[i - 1] + i;
    }

    cin >> n >> k;

    qpll q;
    q.push(make_pair(n, 0));
    dp[n] = 1;
    prv = 0;
    while (!q.empty())
    {
        ll pos = q.front().first, cur = q.front().second;
        q.pop();

        ++cur;
        if (k + sum[cur] > MAX_N)
        {
            continue;
        }

        

        if (pos * 2 <= MAX_N && !dp[pos * 2])
        {
            dp[pos * 2] = 1;
            q.push(make_pair(pos * 2, cur));
        }
        if (pos + 1 <= MAX_N && !dp[pos + 1])
        {
            dp[pos + 1] = 1;
            q.push(make_pair(pos + 1, cur));
        }
        if (pos - 1 >= 0 && !dp[pos - 1])
        {
            dp[pos - 1] = 1;
            q.push(make_pair(pos - 1, cur));
        }
    }

    cout << -1;

END:

    return 0;
}