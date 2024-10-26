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

cll N = 1000;
ll n, orders[2][N] = {{}}, revs[N + 1] = {};

void search(ll pre, ll post0, ll post1)
{
    // cout << pre << " " << post0 << " " << post1 << "\n";
    ll idx;
    if (post0 == post1)
    {
        goto PRINT;
    }
    else if (post0 > post1)
    {
        goto END;
    }
    idx = revs[orders[0][pre]];
    search(pre + 1, post0, idx - 1);
    search(pre + idx - post0 + 1, idx + 1, post1);

PRINT:
    cout << orders[0][pre] << " ";
END:
    return;
}

void solve(void)
{
    cin >> n;
    for (ll i = 0; i < 2; ++i)
    {
        for (ll num, l = 0; l < n; ++l)
        {
            cin >> num;
            orders[i][l] = num;
            revs[num] = l;
        }
    }

    search(0, 0, n - 1);
    cout << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}