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

cll N = 500, M = 500, dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
ll n, m, mat[N][M] = {{}};

ll isValid(ll next, unordered_set<ll> &prev)
{
    ll a = next / m, b = next % m;
    return a >= 0 && a < n && b >= 0 && b < m && prev.find(next) == prev.end();
}

ll search(ll i, ll l, unordered_set<ll> &prev)
{
    ll a, b, next, result = 0;
    if (prev.size() == 4)
    {
        for (auto &p : prev)
        {
            a = p / m, b = p % m;
            result += mat[a][b];
        }

        return result;
    }

    for (auto &dir : dirs)
    {
        a = i + dir[0], b = l + dir[1];
        if (isValid(next = a * m + b, prev))
        {
            prev.insert(next);
            result = max(result, search(a, b, prev));
            prev.erase(next);
        }
    }

    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < m; ++l)
        {
            cin >> mat[i][l];
        }
    }

    ll result = 0, next;
    unordered_set<ll> prev;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < m; ++l)
        {
            next = i * m + l;
            prev.insert(next);
            result = max(result, search(i, l, prev));
            cout << i << " " << l << " " << result << "\n";
            prev.erase(next);
        }
    }

    cout << result << "\n";

    return 0;
}