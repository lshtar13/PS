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

cll MAX_N = 50, MAX_M = MAX_N, directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, mat[MAX_N + 2][MAX_M + 2] = {{}};
ull water[MAX_N + 2][MAX_M + 2] = {{}};

bool isValid(ll i, ll l)
{
    return i > 0 && i <= n && l > 0 && l <= m;
}

int main(void)
{
    // ios::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);

    cin >> n >> m;
    memset(water, -1, sizeof(water));
    for (ll i = 1; i <= n; ++i)
    {
        cin.ignore();
        for (ll l = 1; l <= m; ++l)
        {
            char c;
            cin >> c;
            mat[i][l] = c - '0';
        }
    }

    for (ll i = 1; i <= n; ++i)
    {
        water[i][1] = mat[i][1];
        water[i][m] = mat[i][m];
    }
    for (ll l = 1; l <= m; ++l)
    {
        water[1][l] = mat[1][l];
        water[n][l] = mat[n][l];
    }

    ll dum;
    qpll q;
    for (ll i = 1; i <= n; ++i)
    {
        for (ll l = 1; l <= m; ++l)
        {
            if (water[i][l] == -1)
            {
                water[i][l] = mat[i][l];
            }
            q.push(make_pair(i, l));
            while (!q.empty())
            {
                ll i = q.front().first, l = q.front().second;
                q.pop();
                for (auto &d : directions)
                {
                    ll _i = i + d[0], _l = l + d[1];
                    if (!isValid(_i, _l))
                    {
                        continue;
                    }

                    
                }
            }
        }
    }

    for (ll i = 1; i <= n; ++i)
    {
        for (ll l = 1; l <= m; ++l)
        {
            cout << water[i][l] << " ";
        }
        cout << "\n";
    }

    return 0;
}