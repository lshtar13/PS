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

cll N = 5e5, K = 5e5;
ll n, k, _k = 0;
stack<char> s, result;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    cin.ignore();
    for (ll i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        while (_k < k && !s.empty() && s.top() < c)
        {
            ++_k;
            s.pop();
        }
        s.push(c);
    }

    while (_k < k)
    {
        ++_k;
        s.pop();
    }

    while (!s.empty())
    {
        result.push(s.top());
        s.pop();
    }
    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }

    return 0;
}