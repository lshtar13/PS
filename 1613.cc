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

cll N = 400, K = 50000;
ll n, k, s;
bool mat[N][N] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (ll c0, c1, i = 0; i < k; ++i)
    {
        cin >> c0 >> c1;
        --c0, --c1;
        mat[c0][c1] = true;
    }

    for (ll mid = 0; mid < n; ++mid)
    {
        for (ll i = 0; i < n; ++i)
        {
            for (ll l = 0; l < n; ++l)
            {
                mat[i][l] |= (mat[i][mid] && mat[mid][l]);
            }
        }
    }

    cin >> s;
    for (ll c0, c1, i = 0; i < s; ++i)
    {
        cin >> c0 >> c1;
        --c0, --c1;
        if (mat[c0][c1])
        {
            cout << -1 << "\n";
        }
        else if (mat[c1][c0])
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }

    return 0;
}