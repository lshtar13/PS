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

cll N = 100, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, mat[N][N] = {{}}, depth[N][N] = {{}};

bool isValid(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < n;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            cin >> mat[i][l];
        }
    }

    ll cont = 1;
    qpll q;
    vector<pll> conts[2 * N];
    for (ll a = 0; a < n; ++a)
    {
        for (ll b = 0; b < n; ++b)
        {
            if (mat[a][b] == 1)
            {
                q.push(make_pair(a, b));
                mat[a][b] = ++cont;
                while (!q.empty())
                {
                    ll i = q.front().first, l = q.front().second;
                    conts[cont].emplace_back(make_pair(i, l));
                    q.pop();
                    for (auto &d : directions)
                    {
                        ll _i = i + d[0], _l = l + d[1];
                        if (!isValid(_i, _l) || mat[_i][_l] != 1)
                        {
                            continue;
                        }

                        mat[_i][_l] = cont;
                        q.push(make_pair(_i, _l));
                    }
                }
            }
        }
    }

    cont = 2;
    ll result = N * N + 1;
    for (ll a = 0; a < n; ++a)
    {
        for (ll b = 0; b < n; ++b)
        {
            if (mat[a][b] != cont)
            {
                continue;
            }

            ll depth[N][N] = {{}};
            for (auto &p : conts[cont])
            {
                depth[p.first][p.second] = 1;
                q.push(p);
            }

            while (!q.empty())
            {
                ll i = q.front().first, l = q.front().second;
                q.pop();

                for (auto &d : directions)
                {
                    ll _i = i + d[0], _l = l + d[1];
                    if (!isValid(_i, _l) || depth[_i][_l])
                    {
                        continue;
                    }

                    depth[_i][_l] = depth[i][l] + 1;
                    if (mat[_i][_l] == 0)
                    {
                        q.push(make_pair(_i, _l));
                    }
                    else
                    {
                        // cout << i << " " << l << " "<<depth[i][l]<<"\n";
                        result = min(result, depth[i][l]);
                    }
                }
            }
            ++cont;
        }
    }

    // for (ll i = 0; i < n; ++i)
    // {
    //     for (ll l = 0; l < n; ++l)
    //     {
    //         cout << mat[i][l] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << result - 1 << "\n";

    return 0;
}