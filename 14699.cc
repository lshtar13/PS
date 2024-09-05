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

cll MAX_N = 5000, MAX_M = 1e5;
ll n, m, h[MAX_N + 1] = {},
                   visited[MAX_N + 1] = {}, dp[MAX_N + 1] = {};
vll mat[MAX_N + 1], tree[MAX_N + 1];

ll search(ll k)
{
    if (dp[k])
    {
        return dp[k];
    }

    dp[k] = 1;
    for (auto &t : tree[k])
    {
        dp[k] += search(t);
    }

    return dp[k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> h[i];
    }
    h[0] = 1e6 + 1;
    for (ll a, b, i = 0; i < m; ++i)
    {
        cin >> a >> b;
        if (h[a] < h[b])
        {
            mat[a].emplace_back(b);
        }
        else
        {
            mat[b].emplace_back(a);
        }
    }

    queue<ll> q;
    q.push(min_element(h, h + n) - h);
    visited[q.front()] = 1;
    while (!q.empty())
    {
        ll k = q.front();
        for (auto &_k : mat[k])
        {
            if (!visited[_k])
            {
                tree[k].emplace_back(_k);
            }
        }
        q.pop();
    }

    for (ll i = 1; i <= n; ++i)
    {
        cout << search(i) << "\n";
    }

    return 0;
}
