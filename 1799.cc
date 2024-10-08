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

cll N = 10;
ll n, chess[N][N] = {{}}, isPlaced0[2 * N] = {}, isPlaced1[2 * N] = {};

ll search(ll i, ll l)
{
    if (l >= n)
    {
        ++i, l = 1 - (n % 2);
    }
    if (i >= n)
    {
        return 0;
    }

    ll a = i + l, b = i + n - 1 - l, result = search(i, l + 2);
    if (chess[i][l] && !isPlaced0[a] && !isPlaced1[b])
    {
        isPlaced0[a] = isPlaced1[b] = 1;
        result = max(search(i, l + 2) + 1, result);
        isPlaced0[a] = isPlaced1[b] = 0;
    }

    return result;
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
            cin >> chess[i][l];
        }
    }

    cout << search(0, 0) + search(0, 1) << "\n";

    return 0;
}