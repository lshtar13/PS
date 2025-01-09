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

cll N = 10000, D = 10000, P = 10000;
ll n;
pll arr[N] = {};
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + n);

    ll result = 0;
    for (ll i = 0; i < n; ++i)
    {
        ll d = arr[i].first, p = arr[i].second;
        if (pq.size() >= d)
        {
            result -= pq.top();
            pq.pop();
        }
        pq.push(p);
        result += p;
    }

    cout << result << "\n";

    return 0;
}