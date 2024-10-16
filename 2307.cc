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

cll N = 1000, M = 5000, INF = 1e10;
ll n, m, prevNode[N] = {};
vector<vector<pll>> edges(N);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll a, b, t, i = 0; i < m; ++i)
    {
        cin >> a >> b >> t;
        --a, --b;
        edges[a].emplace_back(make_pair(b, t));
        edges[b].emplace_back(make_pair(a, t));
    }

    ll minDist[N] = {}, visited[N] = {};
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push(make_pair(0, 0));
    minDist[0] = 0, visited[0] = 1;
    while (!pq.empty())
    {
        ll w = pq.top().first, idx = pq.top().second;
        pq.pop();

        if (visited[idx] && w > minDist[idx])
        {
            continue;
        }

        for (auto &p : edges[idx])
        {
            ll _idx = p.first, _w = p.second;
            if (visited[_idx] && minDist[_idx] <= w + _w)
            {
                continue;
            }
            visited[_idx] = 1, minDist[_idx] = w + _w, prevNode[_idx] = idx;
            pq.push(make_pair(w + _w, _idx));
        }
    }

    ll result = 0;
    if (!visited[n - 1])
    {
        cout << 0;
        goto END;
    }

    for (ll from = prevNode[n - 1]; from; from = prevNode[from])
    {
        ll temp, dist[N] = {}, _visited[N] = {};
        pq.push(make_pair(0, 0));
        dist[0] = 0, visited[0] = 1, dist[from] = 0, _visited[from] = 1;
        while (!pq.empty())
        {
            ll w = pq.top().first, idx = pq.top().second;
            pq.pop();

            if (visited[idx] && w > dist[idx])
            {
                continue;
            }

            for (auto &p : edges[idx])
            {
                ll _idx = p.first, _w = p.second;
                if ((_visited[_idx] && w + _w >= dist[_idx]) || _idx == from)
                {
                    continue;
                }

                _visited[_idx] = 1, dist[_idx] = w + _w;
                pq.push(make_pair(w + _w, _idx));
            }
        }

        if (!_visited[n - 1])
        {
            cout << -1 << "\n";
            goto END;
        }
        result = max(result, dist[n - 1] - minDist[n - 1]);
    }

    cout << result << "\n";

END:
    return 0;
}