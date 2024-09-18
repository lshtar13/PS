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

ll hsh[26] = {}, ver[5] = {}, hor[5] = {}, dig[2] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll i = 0; i < 5; ++i)
    {
        for (ll n, l = 0; l < 5; ++l)
        {
            cin >> n;
            hsh[n] = i * 5 + l;
        }
    }

    bool yet = true;
    ll result = 0;
    for (ll n, i, l, k = 1; k <= 25; ++k)
    {
        cin >> n;

        i = hsh[n] / 5, l = hsh[n] % 5;
        if (++hor[i] == 5)
        {
            ++result;
        }
        if (++ver[l] == 5)
        {
            ++result;
        }
        if (i == l && ++dig[0] == 5)
        {
            ++result;
        }
        if (i + l == 4 && ++dig[1] == 5)
        {
            ++result;
        }

        if (yet && result >= 3)
        {
            yet = false;
            cout << k << "\n";
        }
    }

    return 0;
}