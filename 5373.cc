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

char status[6][9] = {{}}, initial[] = {'w', 'y', 'r', 'o', 'g', 'b'};
ll turnInfo[6][4] = {{2, 4, 3, 5}, {5, 3, 4, 2}, {0, 2, 1, 3}, }

void init(void)
{
    for (ll i = 0; i < 6; ++i)
    {
        for (ll l = 0; l < 9; ++l)
        {
            status[i][l] = initial[i];
        }
    }
}

void solve()
{
    ll n;
    cin >> n;
    while (n--)
    {
        char side, dir;
        cin.ignore();
        cin >> side >> dir;
        turn(side, dir);
    }
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