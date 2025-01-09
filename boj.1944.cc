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

cll N = 50, M = 250, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, mat[N][N] = {{}}, parents[M] = {};
vll nodes;

bool isValid(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < n && !mat[i][l];
}

ll find(ll i)
{
    if (parents[i] == i)
    {
        return i;
    }
    else
    {
        return parents[i] = find(parents[i]);
    }
}

void merge(ll i, ll l)
{
    parents[find(l)] = i;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0, key = 2; i < n; ++i)
    {
        cin.ignore();
        for (ll l = 0; l < n; ++l)
        {
            char c;
            cin >> c;
            switch (c)
            {
            case 'S':
            case 'K':
                nodes.emplace_back(i * n + l);
            default:
                mat[i][l] = c == '1';
            }
        }
    }

    priority_queue<pair<ll, pll>, vector<pair<ll, pll>>, greater<pair<ll, pll>>> pq;
    for (ll idx = 0; idx < nodes.size(); ++idx)
    {
        ll node = nodes[idx], visited[N][N] = {{}};
        qll q;
        q.push(node);
        visited[node / n][node % n] = 1;
        while (!q.empty())
        {
            ll i = q.front() / n, l = q.front() % n;
            q.pop();
            for (auto &d : directions)
            {
                ll _i = i + d[0], _l = l + d[1], next = _i * n + _l;
                if (!isValid(_i, _l) || visited[_i][_l])
                {
                    continue;
                }
                q.push(next);
                visited[_i][_l] = visited[i][l] + 1;
            }
        }

        for (ll _idx = 0; _idx < nodes.size(); ++_idx)
        {
            ll _node = nodes[_idx], i = _node / n, l = _node % n;
            if (visited[i][l] > 1)
            {
                pq.push(make_pair(visited[i][l] - 1, make_pair(idx, _idx)));
            }
        }
    }

    for (ll i = 0; i < nodes.size(); ++i)
    {
        parents[i] = i;
    }

    ll result = 0;
    while (!pq.empty())
    {
        ll w = pq.top().first, from = pq.top().second.first, to = pq.top().second.second;
        pq.pop();
        if (find(from) != find(to))
        {
            merge(from, to);
            result += w;
        }
    }

    ll root = find(0);
    for (ll i = 0; i < nodes.size(); ++i)
    {
        if (find(i) != root)
        {
            result = -1;
            goto END;
        }
    }

END:
    cout << result << "\n";

    return 0;
}