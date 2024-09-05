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

cll N_MAX = 1000;
ull n, nums[N_MAX] = {};

bool comp(ull a, ull b)
{
    ull i, l, _a, _b;
    if (!a || !b)
    {
        return a > b;
    }
    for (i = 1; a / i; i *= 10)
        ;
    for (l = 1; b / l; l *= 10)
        ;
    _a = a * l + b, _b = b * i + a;

    return _a > _b;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums, nums + n, comp);

    if (!nums[0] && !nums[n - 1])
    {
        cout << 0;
    }
    else
    {
        for (ll i = 0; i < n; ++i)
        {
            cout << nums[i];
        }
    }
    cout << "\n";

    return 0;
}