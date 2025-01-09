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

cll W = 100, H = 100, directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
ll w, h, st0 = -1, st1 = -1, en0, en1;
ll dp[H][W][4] = {{{}}};
char mat[H][W] = {{}};
bool visited[H][W][4] = {{{}}};

bool isValid(ll i, ll l)
{
    return i >= 0 && i < h && l >= 0 && l < w;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> w >> h;
    for (ll i = 0; i < h; ++i)
    {
        cin.ignore();
        for (ll l = 0; l < w; ++l)
        {
            cin >> mat[i][l];
            if (mat[i][l] == 'C' && st0 == -1)
            {
                st0 = i, st1 = l;
            }
            else if (mat[i][l] == 'C')
            {
                en0 = i, en1 = l;
            }
        }
    }

    pqpll pq;
    pq.push(make_pair(0, st0 * W + st1));
    pq.push(make_pair(0, W * H + st0 * W + st1));
    pq.push(make_pair(0, 2 * W * H + st0 * W + st1));
    pq.push(make_pair(0, 3 * W * H + st0 * W + st1));
    dp[st0][st1][0] = dp[st0][st1][1] = dp[st0][st1][2] = dp[st0][st1][3] = 0;

    while (!pq.empty())
    {
        ll w = -pq.top().first, dir = pq.top().second / (W * H), i = (pq.top().second % (W * H)) / W, l = pq.top().second % W;
        pq.pop();

        if (visited[i][l][dir])
        {
            continue;
        }

        for (ll d : {0, 3, 1})
        {
            ll _dir = (d + dir) % 4, _i = i + directions[_dir][0], _l = l + directions[_dir][1];
            if (!isValid(_i, _l) || mat[_i][_l] == '*' || (dp[_i][_l][_dir] != -1 && dp[_i][_l][_dir] < w + (d != 0)))
            {
                continue;
            }

            dp[_i][_l][_dir] = w + (d != 0);
            pq.push(make_pair(-dp[_i][_l][_dir], _dir * W * H + _i * H + _l));
        }
        visited[i][l][dir] = true;
    }

    ll result = LLONG_MAX;
    for (ll i = 0; i < 4; ++i)
    {
        if (dp[en0][en1][i] != -1)
            result = min(result, dp[en0][en1][i]);
    }

    cout << result << "\n";

    return 0;
}