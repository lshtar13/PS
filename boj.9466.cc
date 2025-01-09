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

cll N = 1e5;
ll n, students[N] = {};

bool search(ll student, short visited[])
{
    if (visited[student] == 2 || visited[student] == -1)
    {
        goto END;
    }

    ++visited[student];
    search(students[student], visited);
    if (visited[student] != 2)
    {
        visited[student] = -1;
    }

END:
    return visited[student] > 0;
}

void solve(void)
{
    cin >> n;
    for (ll to, i = 0; i < n; ++i)
    {
        cin >> to;
        students[i] = --to;
    }

    ll result = 0;
    short visited[N] = {};
    for (ll i = 0; i < n; ++i)
    {
        result += search(i, visited);
    }

    cout << n - result << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}