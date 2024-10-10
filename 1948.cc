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

cll N = 10000, M = 100000;
ll n, m, src, dest, degree[N] = {};
bool checked[N][N] = {{}};
vector<pll> edges[N];
vector<pll> rev[N];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll a, b, c, i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        --a, --b;
        edges[a].emplace_back(make_pair(b, c));
        rev[b].emplace_back(make_pair(a, c));
        ++degree[b];
    }
    cin >> src >> dest;
    --src, --dest;

    ll maxDur[N] = {}, maxPrev[N] = {};
    pqpll pq;
    pq.push(make_pair(0, src));
    while (!pq.empty())
    {
        ll idx = pq.top().second, w = pq.top().first;
        pq.pop();
        if (w != maxDur[idx])
        {
            continue;
        }
        for (auto &p : edges[idx])
        {
            ll _idx = p.first, _w = p.second;
            if (maxDur[_idx] < w + _w)
            {
                maxDur[_idx] = w + _w;
            }
            if (!--degree[_idx])
            {
                pq.push(make_pair(maxDur[_idx], _idx));
            }
        }
    }

    cout << maxDur[dest] << "\n";

    ll result = 0;
    qll q;
    q.push(dest);
    while (!q.empty())
    {
        ll idx = q.front(), tgt = maxDur[idx];
        q.pop();
        for (auto &p : rev[idx])
        {
            if (!checked[idx][p.first] && maxDur[p.first] + p.second == tgt)
            {
                ++result;
                q.push(p.first);
                checked[idx][p.first] = true;
            }
        }
    }

    cout << result << "\n";

    return 0;
}