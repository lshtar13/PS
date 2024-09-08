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

cll N_MAX = 1e3, K_MAX = 1e5;
ll n, k, w, D[N_MAX + 1] = {}, dp[N_MAX + 1] = {}, degree[N_MAX + 1] = {};

ll solve(void)
{
    cin >> n >> k;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> D[i];
    }

    memset(dp, -1, sizeof(ll) * (n + 1));
    memset(degree, 0, sizeof(ll) * (n + 1));
    vector<vll> childs(n + 1), parents(n + 1);
    for (ll x, y, i = 0; i < k; ++i)
    {
        cin >> x >> y;
        ++degree[y];
        childs[x].emplace_back(y);
        parents[y].emplace_back(x);
    }

    cin >> w;

    ll result = 0;
    qll q;
    for (ll i = 1; i <= n; ++i)
    {
        if (!degree[i])
        {
            q.push(i);
            dp[i] = D[i];
        }
    }

    while (!q.empty())
    {
        ll tgt = q.front();
        q.pop();

        for (auto &c : childs[tgt])
        {
            if (!--degree[c])
            {
                for (auto &p : parents[c])
                {
                    dp[c] = max(dp[c], dp[p] + D[c]);
                }
                q.push(c);
            }
        }
    }

    return dp[w];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << "\n";
    }

    return 0;
}