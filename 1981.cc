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

cll MAX_N = 100;
ll n, mat[MAX_N][MAX_N] = {{}}, directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValidCord(pll c)
{
    return c.first >= 0 && c.first < n && c.second >= 0 && c.second < n;
}

bool isValid(ll gap)
{
    // herere
    vll minV[MAX_N][MAX_N] = {{}}, maxV[MAX_N][MAX_N] = {{}};
    queue<pair<pll, pll>> q;
    q.push(make_pair(make_pair(0, 0), make_pair(mat[0][0], mat[0][0])));
    while (!q.empty())
    {
        ll i = q.front().first.first, l = q.front().first.second, maxV = q.front().second.first, minV = q.front().second.second;
        q.pop();
        if (i == n - 1 && l == n - 1)
        {
            return true;
        }

        for (pll d : {pll(i + 1, l), pll(i - 1, l), pll(i, l + 1), pll(i, l - 1)})
        {
            if (!isValidCord(d) || visited[d.first][d.second])
            {
                continue;
            }

            pll minmax = make_pair(max(maxV, mat[d.first][d.second]),
                                   min(minV, mat[d.first][d.second]));
            visited[d.first][d.second] = 1;

            if (gap >= minmax.first - minmax.second)
            {
                q.push(make_pair(d, minmax));
            }
        }
    }

    return false;
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

    ll st = 0, en = 200, mid, ans;
    while (st <= en)
    {
        cout << st << " " << en << '\n';
        mid = (st + en) / 2;
        if (isValid(mid))
        {
            ans = mid, en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}