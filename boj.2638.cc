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

cll directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m;
vector<vector<ll>> mat, results, cnt;

inline bool isValid(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < m;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    // 동적으로 배열 크기 설정
    mat.assign(n, vector<ll>(m, 0));
    results.assign(n, vector<ll>(m, 500));
    cnt.assign(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < m; ++l)
        {
            cin >> mat[i][l];
        }
    }

    qpll q;
    for (ll i = 0; i < n; ++i)
    {
        if (!mat[i][0])
        {
            mat[i][0] = -1;
            results[i][0] = 0;
            q.push(make_pair(i, 0));
        }
        if (!mat[i][m - 1])
        {
            mat[i][m - 1] = -1;
            results[i][m - 1] = 0;
            q.push(make_pair(i, m - 1));
        }
    }

    for (ll l = 0; l < m; ++l)
    {
        if (!mat[0][l])
        {
            mat[0][l] = -1;
            results[0][l] = 0;
            q.push(make_pair(0, l));
        }
        if (!mat[n - 1][l])
        {
            mat[n - 1][l] = -1;
            results[n - 1][l] = 0;
            q.push(make_pair(n - 1, l));
        }
    }

    for (ll i, l, _i, _l; !q.empty();)
    {
        i = q.front().first, l = q.front().second;
        q.pop();

        for (auto &d : directions)
        {
            _i = i + d[0], _l = l + d[1];
            if (!isValid(_i, _l))
            {
                continue;
            }

            if (mat[_i][_l] > 0 && (++cnt[_i][_l] >= 2) && results[_i][_l] > results[i][l] + 1)
            {
                results[_i][_l] = results[i][l] + 1;
                q.push(make_pair(_i, _l));
            }
            else if (!mat[_i][_l])
            {
                mat[_i][_l] = -1, results[_i][_l] = results[i][l];
                q.push(make_pair(_i, _l));
            }
        }
    }

    ll result = 0;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < m; ++l)
        {
            result = max(result, results[i][l]);
        }
    }
    cout << result << "\n";

    return 0;
}
