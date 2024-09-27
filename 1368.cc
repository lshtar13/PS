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

cll N = 300;
ll n, w[N] = {}, p[N][N] = {{}}, isIn[N] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> w[i];
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = 0; l < n; ++l)
        {
            cin >> p[i][l];
        }
    }

    return 0;
}