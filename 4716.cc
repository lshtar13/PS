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

void solve(ll n, ll ab[])
{
    ll result = 0, team[1000][3] = {{}};
    pqpll pq;
    for (ll i = 0; i < n; ++i)
    {
        cin >> team[i][0] >> team[i][1] >> team[i][2];
        pq.push(make_pair(abs(team[i][1] - team[i][2]), i));
    }

    while (!pq.empty())
    {
        ll consume, i = pq.top().second, _ab = team[i][1] > team[i][2];
        pq.pop();

        // near
        consume = min(ab[_ab], team[i][0]);
        ab[_ab] -= consume, team[i][0] -= consume,
            result += consume * team[i][_ab + 1];

        // far
        _ab = !_ab;
        consume = min(ab[_ab], team[i][0]);
        ab[_ab] -= consume, team[i][0] -= consume,
            result += consume * team[i][_ab + 1];
    }
    cout << result << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll n, ab[2] = {}; cin >> n >> ab[0] >> ab[1] && (n || ab[0] || ab[1]);)
    {
        solve(n, ab);
    }

    return 0;
}