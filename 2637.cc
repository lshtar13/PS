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

cll N = 100;
ll n, m, result[N][N] = {{}};
bool visited[N] = {};
vector<vector<pll>> edges(N);

void search(ll node)
{
    if (visited[node])
    {
        return;
    }

    visited[node] = true;
    for (auto &p : edges[node])
    {
        search(p.first);
        for (ll i = 0; i < n; ++i)
        {
            result[node][i] += result[p.first][i] * p.second;
        }
    }

    if (!edges[node].size())
    {
        result[node][node] = 1;
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll x, y, k, i = 0; i < m; ++i)
    {
        cin >> x >> y >> k;
        --x, --y;
        edges[x].emplace_back(make_pair(y, k));
    }

    search(n - 1);
    for (ll i = 0; i < n; ++i)
    {
        if (result[n - 1][i])
        {
            cout << i + 1 << " " << result[n - 1][i] << "\n";
        }
    }

    return 0;
}