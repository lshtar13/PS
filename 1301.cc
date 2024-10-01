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

cll PREV = 37, BEADS = 170000; // 11^5
ll n, nbead = 0, dp[PREV][BEADS] = {{}};

ll search(ll prev, ll beads)
{
    if (dp[prev][beads] != -1)
    {
        return dp[prev][beads];
    }

    if (beads == 0)
    {
        return dp[prev][beads] = 1;
    }

    ll result = 0, prev0 = prev / (n + 1) - 1, prev1 = prev % (n + 1) - 1;
    for (ll bead, i = 0, l = 1; i < n; ++i, l *= 11)
    {
        bead = beads % (l * 11), bead /= l;
        if (prev0 == i || prev1 == i || !bead)
        {
            continue;
        }
        result += search((prev1 + 1) * (n + 1) + i + 1, beads - l);
    }
    return dp[prev][beads] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    ll beads = 0;
    for (ll bead, i = 0; i < n; ++i)
    {
        cin >> bead;
        beads *= 11;
        beads += bead;
    }

    cout << search(0, beads) << "\n";

    return 0;
}