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
typedef const vector<vll> cvvll;

cll K = 30, W = 200, H = 200;
cvvll dir0 = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {1, -2}, {2, -1}},
      dir1 = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
ll k, w, h, mat[H][W] = {{}}, minAcc[H][W][K + 1] = {{{}}};

bool isValid(ll i, ll l)
{
    return i >= 0 && i < h && l >= 0 && l < w && !mat[i][l];
}

void pushQll(ll i, ll l, ll _k, ll dk, qll &q, cvvll &dir)
{
    ll _i, _l, value;
    for (auto &d : dir)
    {
        if (!isValid(_i = i + d[0], _l = l + d[1]) || minAcc[_i][_l][_k + dk])
        {
            continue;
        }

        minAcc[_i][_l][_k + dk] = minAcc[i][l][_k] + 1;
        value = _i + _l * 200 + (_k + dk) * 200 * 200;
        q.push(value);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> w >> h;
    for (ll i = 0; i < h; ++i)
    {
        for (ll l = 0; l < w; ++l)
        {
            cin >> mat[i][l];
        }
    }

    qll q;
    minAcc[0][0][0] = 1;
    q.push(0);
    while (!q.empty())
    {
        ll num = q.front(), i, l, _k;
        i = num % 200, num /= 200,
        l = num % 200, num /= 200,
        _k = num % 200, num /= 200;
        q.pop();

        // cout << i << " " << l << " " << _k << "\n";
        if (_k < k)
        {
            pushQll(i, l, _k, 1, q, dir0);
        }
        pushQll(i, l, _k, 0, q, dir1);
    }

    ll result = LLONG_MAX;
    for (auto &v : minAcc[h - 1][w - 1])
    {
        if (v > 0)
        {
            result = min(result, v);
        }
    }

    if (result != LLONG_MAX)
    {
        cout << result - 1;
    }
    else
    {
        cout << -1;
    }

    return 0;
}