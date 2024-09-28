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
typedef unsigned char uc;

cll lIdx = 6, rIdx = 2;
ll k;
uc wheels[4][9] = {{}};
qpll wq;

void turn(ll n, ll d, ll k)
{
    // left
    if (k <= 0 && n > 0 && wheels[n][lIdx] != wheels[n - 1][rIdx])
    {
        turn(n - 1, -d, -1);
    }
    // right
    if (k >= 0 && n < 3 && wheels[n][rIdx] != wheels[n + 1][lIdx])
    {
        turn(n + 1, -d, 1);
    }
    // self
    wq.push(make_pair(n, d));
}

void apply()
{
    while (!wq.empty())
    {
        ll n = wq.front().first, d = wq.front().second;
        uc wheel[9] = {};
        d = (d + 8) % 8;
        for (ll i = 0; i < 8; ++i)
        {
            wheel[(i + d) % 8] = wheels[n][i];
        }
        for (ll i = 0; i < 8; ++i)
        {
            wheels[n][i] = wheel[i];
        }
        wq.pop();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (auto &wheel : wheels)
    {
        cin >> wheel;
    }

    cin >> k;
    for (ll num, direction; k--;)
    {
        cin >> num >> direction;
        turn(num - 1, direction, 0);
        apply();
    }

    ll result = 0;
    if (wheels[0][0] - '0')
    {
        result += 1;
    }
    if (wheels[1][0] - '0')
    {
        result += 2;
    }
    if (wheels[2][0] - '0')
    {
        result += 4;
    }
    if (wheels[3][0] - '0')
    {
        result += 8;
    }
    cout << result;

    return 0;
}