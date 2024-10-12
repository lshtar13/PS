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

cll N = 1000, M = 1000;
ll t, n, m, sumA[N + 1] = {}, sumB[M + 1] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> sumA[i];
        sumA[i] += sumA[i - 1];
    }

    cin >> m;
    for (ll i = 1; i <= m; ++i)
    {
        cin >> sumB[i];
        sumB[i] += sumB[i - 1];
    }

    vll colA, colB;
    for (ll i = 0; i < n; ++i)
    {
        for (ll l = i + 1; l <= n; ++l)
        {
            colA.emplace_back(sumA[l] - sumA[i]);
        }
    }
    for (ll i = 0; i < m; ++i)
    {
        for (ll l = i + 1; l <= m; ++l)
        {
            colB.emplace_back(sumB[l] - sumB[i]);
        }
    }
    sort(colB.begin(), colB.end());

    ll result = 0;
    for (auto &sum : colA)
    {
        result += upper_bound(colB.begin(), colB.end(), t - sum) - lower_bound(colB.begin(), colB.end(), t - sum);
    }
    cout << result << "\n";

    return 0;
}