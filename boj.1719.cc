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

cll N = 200, M = 10000, INF = 2e6;
ll n, m, prv[N][N] = {{}}, mat[N][N] = {{}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            mat[i][l] = i == l ? 0 : INF;
        }
    }

    for (ll s0, s1, w, i = 0; i < m; ++i)
    {
        cin >> s0 >> s1 >> w;
        --s0, --s1;
        mat[s0][s1] = w, mat[s1][s0] = w;
        prv[s0][s1] = s1, prv[s1][s0] = s0;
    }

    for (ll k = 0; k < n; ++k)
    {
        for (ll i = 0; i < n; ++i)
        {
            for (ll l = 0; l < n; ++l)
            {
                ll w = mat[i][k] + mat[k][l];
                if (mat[i][l] > w)
                {
                    mat[i][l] = w, prv[i][l] = prv[i][k];
                }
            }
        }
    }

    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            if (i == l)
            {
                cout << "- ";
            }
            else
            {
                cout << prv[i][l] + 1 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}