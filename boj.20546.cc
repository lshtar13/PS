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

const string B = "BNP", T = "TIMING", S = "SAMESAME";
ll balance[2] = {}, equity[2] = {}, price[14] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> balance[0];
    balance[1] = balance[0];
    for (auto &p : price)
    {
        cin >> p;
    }

    // BNP
    for (const auto &p : price)
    {
        equity[0] += balance[0] / p, balance[0] %= p;
    }

    // TIMING
    for (ll d = 3; d < 14; ++d)
    {
        if (price[d - 3] < price[d - 2] && price[d - 2] < price[d - 1] && price[d - 1] < price[d])
        {
            balance[1] += equity[1] * price[d], equity[1] = 0;
        }

        if (price[d - 3] > price[d - 2] && price[d - 2] > price[d - 1] && price[d - 1] > price[d])
        {
            equity[1] += balance[1] / price[d], balance[1] %= price[d];
        }
    }

    equity[0] *= price[13], equity[1] *= price[13];
    equity[0] += balance[0], equity[1] += balance[1];
    if (equity[0] > equity[1])
    {
        cout << B << "\n";
    }
    else if (equity[0] < equity[1])
    {
        cout << T << "\n";
    }
    else
    {
        cout << S << "\n";
    }

    return 0;
}