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

ll calc(ll r, ll c)
{
    ll k = max(abs(r), abs(c)), n;
    if (r == k)
    {
        n = (2 * k + 1) * (2 * k + 1) - (k - c);
    }
    else if (c == k)
    {
        n = (2 * k - 1) * (2 * k - 1) + (k - r);
    }
    else if (r == -k)
    {
        n = (4 * k * k + 1) - k - c;
    }
    else
    {
        n = (4 * k * k + 1) + k + r;
    }

    return n;
}

ll getLen(ll r, ll c)
{
    ll v = calc(r, c), len = 0;
    for (ll k = 1; v / k; k *= 10, ++len)
        ;
    return len;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll maxLen = 0, v, len, k;
    maxLen = max(maxLen, getLen(r1, c1));
    maxLen = max(maxLen, getLen(r1, c2));
    maxLen = max(maxLen, getLen(r2, c1));
    maxLen = max(maxLen, getLen(r2, c2));

    for (ll r = r1; r <= r2; ++r)
    {
        for (ll c = c1; c <= c2; ++c)
        {
            cout << setw(maxLen) << setfill(' ') << calc(r, c) << " ";
        }
        cout << "\n";
    }

    return 0;
}