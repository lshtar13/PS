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

cll D = 1e9, N = 5e4, M = N;
ll d, n, m, stones[N + 1] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> d >> n >> m;
    for (ll i = 0; i < n; ++i)
    {
        cin >> stones[i];
    }
    stones[n] = d;
    sort(stones, stones + n + 1);

    ll st = 0, en = d, ans;
    while (st <= en)
    {
        ll mid = (st + en) / 2, prv = 0, deleted = 0;
        for (ll i = 0; i <= n; ++i)
        {
            if (stones[i] - prv < mid)
            {
                ++deleted;
                continue;
            }
            prv = stones[i];
        }

        if (prv != d || deleted > m)
        {
            en = mid - 1;
        }
        else
        {
            ans = mid, st = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}