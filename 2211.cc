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

cll N = 1000, C = 10, INF = 1e4 + 1, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m;

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    vector<vector<pll>> edges(n);
    for (ll a, b, c, i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        --a, --b;
        edges[a].emplace_back(make_pair(b, c));
        edges[b].emplace_back(make_pair(a, c));
    }

    vll minDist(n, INF), prev(n, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    minDist[0] = 0, prev[0] = -1;
    pq.push(make_pair(0, 0));
    while (!pq.empty())
    {
        ll node = pq.top().second, dist = pq.top().first;
        pq.pop();

        if (minDist[node] < dist)
        {
            continue;
        }

        for (auto &e : edges[node])
        {
            ll _node = e.first, w = e.second, newDist = dist + w;
            if (newDist < minDist[_node])
            {
                minDist[_node] = newDist, prev[_node] = node;
                pq.push(make_pair(newDist, _node));
            }
        }
    }

    cout << n - 1 << "\n";
    for (ll i = 1; i < n; ++i)
    {
        cout << prev[i] + 1 << " " << i + 1 << "\n";
    }

    return 0;
}