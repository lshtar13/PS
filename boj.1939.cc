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
typedef vector<vector<pll>> vvpll;

cll N = 10000;
ll n, m, src, dest;
vvpll edges(N);

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
        edges[b].emplace_back(make_pair(a, c));
    }
    cin >> src >> dest;
    --src, --dest;

    ll st = 0, en = 1e9, ans;
    while (st <= en)
    {
        ll mid = (st + en) / 2;
        bool visited[N] = {};
        qll q;
        visited[src] = true;
        q.push(src);
        while (!q.empty())
        {
            ll from = q.front();
            q.pop();
            for (auto &p : edges[from])
            {
                if (visited[p.first] || p.second < mid)
                {
                    continue;
                }

                visited[p.first] = true;
                q.push(p.first);
            }
        }

        if (visited[dest])
        {
            ans = mid, st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}