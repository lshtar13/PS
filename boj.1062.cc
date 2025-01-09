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
typedef set<ll> sll;
typedef unordered_set<ll> usll;

ll n, k;
vector<pll> v;

ll _search(ll idx, ll num, ll status)
{
    if (num > k)
    {
        return 0;
    }

    ll result = 0;
    if (idx >= 26)
    {
        for (auto &p : v)
        {
            if (!(p.first ^ (p.first & status)))
            {
                result += p.second;
            }
        }

        return result;
    }

    if (!(status & (1 << idx)))
    {
        result = max(result, _search(idx + 1, num + 1, status | (1 << idx)));
    }
    result = max(result, _search(idx + 1, num, status));
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll genesis = 1;
    genesis |= (1 << 'n' - 'a');
    genesis |= (1 << 't' - 'a');
    genesis |= (1 << 'i' - 'a');
    genesis |= (1 << 'c' - 'a');

    cin >> n >> k;
    for (ll bitMsk = 0, i = 0; i < n; ++i, bitMsk = 0)
    {
        string s;
        cin >> s;
        for (auto &c : s)
        {
            bitMsk |= (1 << (c - 'a'));
        }

        bool found = false;
        for (auto &p : v)
        {
            if (p.first == bitMsk)
            {
                ++p.second;
                found = true;
                break;
            }
        }
        if (!found)
        {
            v.emplace_back(make_pair(bitMsk, 1));
        }
    }

    cout << _search(1, 5, genesis) << "\n";

    return 0;
}