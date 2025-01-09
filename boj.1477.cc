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

cll N = 50, M = 100, LEN = 1000;
ll n, m, len;
set<ll> rest;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> len;
    for (ll area, i = 0; i < n; ++i)
    {
        cin >> area;
        rest.insert(area);
    }
    rest.insert(0);
    rest.insert(len);

    ll st = 1, en = LEN, ans,
       mid, prev, _m;
    while (st <= en)
    {
        mid = (st + en) / 2, prev = 0, _m = m;

        bool isValid = true;
        for (auto &next : rest)
        {
            if (!isValid)
            {
                break;
            }

            while ((next - prev) > mid && isValid)
            {
                if (_m == 0)
                {
                    isValid = false;
                    break;
                }
                prev += mid, --_m;
            }
            prev = next;
        }

        if (isValid)
        {
            ans = mid;
            en = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}