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

cll N = 1000, M = 1e5, K = N;
ll n, m, k, root, parents[N] = {};
vll stations;
vector<vector<pll>> edges(N);

ll find(ll node)
{
    if (parents[node] == node)
    {
        return node;
    }

    return parents[node] = find(parents[node]);
}

void merge(ll u, ll v)
{
    parents[v] = find(u);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k >> root;
    --root;
    for (ll i = 0; i < n; ++i)
    {
        parents[i] = i;
    }
    for (ll station, i = 1; i < k; ++i)
    {
        cin >> station;
        merge(root, --station);
    }

    for (ll u, v, w, i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        --u, --v;
        edges[u].emplace_back(make_pair(v, w));
        edges[v].emplace_back(make_pair(u, w));
    }

    pqpll pq;
    for (ll node = 0; node < n; ++node)
    {
        if (find(node) != root)
        {
            continue;
        }

        for (auto &edge : edges[node])
        {
            pq.push(make_pair(-edge.second, node * N + edge.first));
        }
    }

    ll result = 0;
    while (!pq.empty())
    {
        ll w = -pq.top().first, u = pq.top().second / N, v = pq.top().second % N;
        pq.pop();

        if (find(u) == find(v))
        {
            continue;
        }

        merge(u, v);
        result += w;
        for (auto &edge : edges[v])
        {
            pq.push(make_pair(-edge.second, v * N + edge.first));
        }
    }

    cout << result << "\n";

    return 0;
}