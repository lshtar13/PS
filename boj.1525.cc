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

cll dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll nine[10] = {1};
qpll q;
unordered_set<ll> visited;

inline bool isValid(ll i, ll l)
{
    return i >= 0 && i < 3 && l >= 0 && l < 3;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll init = 0, goal = 0;
    for (ll m, k = 0; k < 9; ++k)
    {
        cin >> m;
        init += m * nine[k], nine[k + 1] = nine[k] * 9;
    }
    for (ll k = 1; k < 9; ++k)
    {
        goal += nine[k - 1] * k;
    }

    if (init == goal)
    {
        cout << 0 << "\n";
        goto END;
    }
    visited.insert(init);
    q.push(make_pair(init, 0));
    while (!q.empty())
    {
        ll status = q.front().first, h = q.front().second, mat[3][3] = {{}}, i, l;
        q.pop();
        for (ll k = 0; k < 9; ++k)
        {
            mat[k / 3][k % 3] = status % 9, status /= 9;
            if (!mat[k / 3][k % 3])
            {
                i = k / 3, l = k % 3;
            }
        }

        for (auto &d : dirs)
        {
            ll hs = 0, _i = i + d[0], _l = l + d[1];
            if (isValid(_i, _l))
            {
                swap(mat[i][l], mat[_i][_l]);
                for (ll k = 0; k < 9; ++k)
                {
                    hs += mat[k / 3][k % 3] * nine[k];
                }
                if (hs == goal)
                {
                    cout << h + 1 << "\n";
                    goto END;
                }
                if (visited.find(hs) == visited.end())
                {
                    visited.insert(hs);
                    q.push(make_pair(hs, h + 1));
                }
                swap(mat[i][l], mat[_i][_l]);
            }
        }
    }

    cout << -1 << "\n";

END:

    return 0;
}