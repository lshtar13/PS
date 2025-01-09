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

ll s, n, k, r1, r2, c1, c2, resultMat[50][50] = {{}};

void fillMat(ll sec, ll from1, ll to1, ll from2, ll to2, ll _from1, ll _to1, ll _from2, ll _to2)
{
    ll _length = pow(n, sec - 1), length = pow(n, sec);

    for (ll i = 0; i < length; i += _length)
    {
        for (ll l = 0; l < length; l += _length)
        {
            fillMat(sec - 1, from1%_length, to1%_length, from2%_length, to2%_length, )
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;

    fillMat(s, r1, c1, r2, c2, 0, r2 - r1 + 1, 0, c2 - c1 + 1);

    return 0;
}