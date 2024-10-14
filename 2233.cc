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

cll N = 2000;
ll n, x, y, same[2 * N + 1] = {}, parents[2 * N + 1][11] = {{}};

ll query(ll idx, ll k)
{
    for (ll i = 10; i >= 0; --i)
    {
        if (k & (1 << i))
        {
            idx = parents[idx][i];
        }
    }

    return idx;
}

ll depth(ll i)
{
    ll st = 0, en = 2000, ans;
    while (st <= en)
    {
        ll mid = (st + en) / 2;
        if (query(i, mid) <= 1)
        {
            ans = mid, en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin.ignore();
    stack<ll> s;
    s.push(0);
    for (ll t, i = 1; i <= 2 * n; ++i)
    {
        char c;
        cin >> c;
        if (c == '0')
        {
            s.push(i);
        }
        else
        {
            t = s.top();
            same[t] = i, same[i] = t;
            s.pop();
            parents[t][0] = s.top();
        }
    }
    cin.ignore();
    cin >> x >> y;
    x = min(x, same[x]), y = min(y, same[y]);

    for (ll i = 1; i <= n; ++i)
    {
        for (ll l = 1; l < 11; ++l)
        {
            parents[i][l] = parents[parents[i][l - 1]][l - 1];
        }
    }

    ll depthX = depth(x), depthY = depth(y), minDepth = min(depthX, depthY),
       dx = depthX - minDepth, dy = depthY - minDepth;
    ll st = 0, en = minDepth, ans, ansDepth;
    while (st <= en)
    {
        ll mid = (st + en) / 2, _depthX = dx + mid, _depthY = dy + mid,
           _x = query(x, _depthX), _y = query(y, _depthY);
        if (_x == _y)
        {
            ansDepth = mid, en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    ans = query(x, dx + ansDepth);

    cout << min(ans, same[ans]) << " " << max(ans, same[ans]);

    return 0;
}