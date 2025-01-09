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

cll N = 50, M = 50, directions[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
ll n, m, mat[M][N] = {{}}, room[M][N] = {{}}, roomSize[M * N] = {};

bool isValid(ll i, ll l)
{
    return i >= 0 && i < m && l >= 0 && l < n;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i < m; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            cin >> mat[i][l];
        }
    }

    ll roomNo = 0, maxSize = 0, maxSum = 0;
    qpll q;
    for (ll a = 0; a < m; ++a)
    {
        for (ll b = 0; b < n; ++b)
        {
            if (room[a][b])
            {
                continue;
            }

            room[a][b] = ++roomNo, roomSize[roomNo] = 1;
            q.push(make_pair(a, b));
            while (!q.empty())
            {
                ll i = q.front().first, l = q.front().second;
                q.pop();
                for (ll d = 0; d < 4; ++d)
                {
                    ll _i = i + directions[d][0], _l = l + directions[d][1];
                    if (!isValid(_i, _l) || room[_i][_l] || (mat[i][l] & (1 << d)))
                    {
                        continue;
                    }

                    ++roomSize[roomNo], room[_i][_l] = roomNo;
                    q.push(make_pair(_i, _l));
                }
            }

            maxSize = max(maxSize, roomSize[roomNo]);
        }
    }

    for (ll i = 0; i < m; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            for (ll d = 0; d < 4; ++d)
            {
                ll _i = i + directions[d][0], _l = l + directions[d][1];
                if (!isValid(_i, _l) || room[i][l] == room[_i][_l] || !(mat[i][l] & (1 << d)))
                {
                    continue;
                }

                maxSum = max(maxSum, roomSize[room[i][l]] + roomSize[room[_i][_l]]);
            }
        }
    }

    cout << roomNo << "\n";
    cout << maxSize << "\n";
    cout << maxSum << "\n";

    return 0;
}