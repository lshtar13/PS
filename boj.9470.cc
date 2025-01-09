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

cll M = 1000;

void solve(void)
{
    ll k, m, p, degree[M] = {}, order[M] = {};
    cin >> k >> m >> p;
    vvll edges(m);
    for (ll a, b, i = 0; i < p; ++i)
    {
        cin >> a >> b;
        edges[--a].emplace_back(--b);
        ++degree[b];
    }

    qll q;
    for (ll i = 0; i < m; ++i)
    {
        if (!degree[i])
        {
            order[i] = 1001;
            q.push(i);
        }
    }

    ll result;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();

        for (auto &av : edges[node])
        {
            if (order[av] / 1000 == order[node] / 1000)
            {
                ++order[av];
            }
            else
            {
                order[av] = max(order[av], order[node]);
            }

            if (!--degree[av])
            {
                order[av] = (order[av] / 1000 + (order[av] % 1000 > 1)) * 1000 + 1;
                q.push(av);
                result = order[av];
            }
        }
    }

    cout << k << " " << result / 1000 << "\n";
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
        solve();
    }

    return 0;
}