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

cll K_MAX = 50, N_MAX = 50;
ll k, n, nums[K_MAX] = {};

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

    cin >> k >> n;
    for (ll i = 0; i < k; ++i)
    {
        cin >> nums[i];
    }
    sort(nums, nums + k, comp);

    for (ll i = 0; i <= n - k; ++i)
    {
        cout << nums[0];
    }
    for (ll i = 1; i < k; ++i)
    {
        cout << nums[i];
    }
    cout << "\n";

    return 0;
}