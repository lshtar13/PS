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

cll N = 100, M = 100, DIR = 4, INF = 1e9,
    directions[4][3][2] = {{{0, 1}, {0, 2}, {0, 3}}, {{0, -1}, {0, -2}, {0, -3}}, {{1, 0}, {2, 0}, {3, 0}}, {{-1, 0}, {-2, 0}, {-3, 0}}};
ll n, m, record[M][N][DIR] = {{}};
bool industry[M][N] = {{}};

bool isValid(ll i, ll l)
{
    return i >= 0 && i < m && l >= 0 && l < n;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m >> n;
    for (ll i = 0; i < m; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            cin >> industry[i][l];
            for (ll d = 0; d < 4; ++d)
            {
                record[i][l][d] = INF;
            }
        }
    }

    pair<pll, ll> st, en;
    cin >> st.first.first >> st.first.second >> st.second;
    cin >> en.first.first >> en.first.second >> en.second;
    --st.first.first, --st.first.second, --st.second;
    --en.first.first, --en.first.second, --en.second;
    queue<pair<pll, ll>> q;
    q.push(st);
    record[st.first.first][st.first.second][st.second] = 0;
    while (!q.empty())
    {
        ll i = q.front().first.first, l = q.front().first.second, dir = q.front().second;
        q.pop();

        for (auto &d : directions[dir])
        {
            ll _i = i + d[0], _l = l + d[1];
            if (!isValid(_i, _l) || record[_i][_l][dir] != INF)
            {
                continue;
            }
            else if (industry[_i][_l])
            {
                break;
            }
            record[_i][_l][dir] = record[i][l][dir] + 1;
            q.push(make_pair(make_pair(_i, _l), dir));
        }

        for (ll d = 0; d < 4; ++d)
        {
            if ((dir < 2 && d < 2) || (dir > 1 && d > 1) || record[i][l][d] != INF)
            {
                continue;
            }

            record[i][l][d] = record[i][l][dir] + 1;
            q.push(make_pair(make_pair(i, l), d));
        }
    }

    cout << record[en.first.first][en.first.second][en.second];

    return 0;
}