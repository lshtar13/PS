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

cll MAX_N = 1000, MAX_W = 1000;
ll n, w, cases[MAX_W + 1][2] = {{}},
                       dpCost[MAX_W + 1][MAX_W + 1] = {{}}, dpPrev[MAX_W + 1][MAX_W + 1][2] = {{{}}};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> w;
    for (ll i = 1; i <= w; ++i)
    {
        cin >> cases[i][0] >> cases[i][1];
    }

    dpCost[1][0] = abs(1 - cases[1][0]) + abs(1 - cases[1][1]),
    dpCost[0][1] = abs(n - cases[1][0]) + abs(n - cases[1][1]);
    dpPrev[1][0][0] = dpPrev[1][0][1] = dpPrev[0][1][0] = dpPrev[0][1][1] = 0;

    for (ll c = 2; c <= w; ++c)
    {
        // A
        dpCost[c][c - 1] = MAX_N * 2 * MAX_W;
        for (ll gap, prev = 0; prev < c - 1; ++prev)
        {
            dpCost[c][prev] = dpCost[c - 1][prev] + abs(cases[c - 1][0] - cases[c][0]) + abs(cases[c - 1][1] - cases[c][1]);
            dpPrev[c][prev][0] = c - 1, dpPrev[c][prev][1] = prev;
            gap = prev ? abs(cases[c][0] - cases[prev][0]) + abs(cases[c][1] - cases[prev][1])
                       : cases[c][0] + cases[c][1] - 2;
            if (dpCost[c][c - 1] > dpCost[prev][c - 1] + gap)
            {
                dpCost[c][c - 1] = dpCost[prev][c - 1] + gap,
                              dpPrev[c][c - 1][0] = prev, dpPrev[c][c - 1][1] = c - 1;
            }
        }
        // B
        dpCost[c - 1][c] = MAX_N * 2 * MAX_W;
        for (ll gap, prev = 0; prev < c - 1; ++prev)
        {
            dpCost[prev][c] = dpCost[prev][c - 1] + abs(cases[c - 1][0] - cases[c][0]) + abs(cases[c - 1][1] - cases[c][1]);
            dpPrev[prev][c][0] = prev, dpPrev[prev][c][1] = c - 1;
            gap = prev ? abs(cases[c][0] - cases[prev][0]) + abs(cases[c][1] - cases[prev][1])
                       : 2 * n - cases[c][0] - cases[c][1];
            if (dpCost[c - 1][c] > dpCost[c - 1][prev] + gap)
            {
                dpCost[c - 1][c] = dpCost[c - 1][prev] + gap,
                           dpPrev[c - 1][c][0] = c - 1, dpPrev[c - 1][c][1] = prev;
            }
        }
    }

    // for (ll i = 0; i <= w; ++i)
    // {
    //     for (ll l = 0; l <= w; ++l)
    //     {
    //         cout << dpCost[i][l] << " ";
    //     }
    //     cout << "\n";
    // }

    ll a, b, result = MAX_N * 2 * MAX_W;
    for (ll prev = 0; prev < w; ++prev)
    {
        if (dpCost[prev][w] < result)
        {
            a = prev, b = w, result = dpCost[prev][w];
        }

        if (dpCost[w][prev] < result)
        {
            a = w, b = prev, result = dpCost[w][prev];
        }
    }

    cout << result << "\n";
    vll result1(w);
    while (w--)
    {
        ll _a, _b;
        result1[w] = a == w + 1 ? 1 : 2;
        _a = dpPrev[a][b][0], _b = dpPrev[a][b][1],
        a = _a, b = _b;
    }
    for (auto &pol : result1)
    {
        cout << pol << "\n";
    }

    return 0;
}