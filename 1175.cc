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

cll N = 50, M = 50, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m, st, c, mat[N * M][2] = {{}};

inline bool isValidCord(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < m;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin.ignore();
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < m; ++l)
        {
            char c;
            cin >> c;
            mat[i * m + l][0] = c;
            if (c == 'S')
            {
                st = i * m + l;
            }
        }
        cin.ignore();
    }

    qpll q;
    for (ll i = 0; i < 4; ++i)
    {
        q.push({st, (1 << i)});
        mat[st][1] = (1 << i);
    }
    c = 0, mat[st][0] = '.';
    while (!q.empty())
    {
        ll idx = q.front().first, i = idx / m, l = idx % m, status = q.front().second;
        q.pop();
        if (mat[idx][0] == '#')
        {
            continue;
        }
        else if (mat[idx][0] == 'C')
        {
            // ehrere
            cout << i << " " << l << " " << mat[idx][dir] << "\n";
            ++c, mat[idx][4] = '.';
        }

        if (c == 2)
        {
            cout << mat[idx][dir] - 1 << "\n";
            goto END;
        }

        for (ll d = 0; d < 4; ++d)
        {
            ll _i = i + directions[d][0], _l = l + directions[d][1], _idx = _i * m + _l;
            if (d == dir || !isValidCord(_i, _l) || mat[_idx][d])
            {
                continue;
            }
            mat[_idx][d] = mat[idx][dir] + 1;
            q.push({_idx, d});
        }
    }

    cout << -1 << "\n";
END:

    return 0;
}