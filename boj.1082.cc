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

cll N = 10, K = 50, M = 50;
ll n, price[N] = {}, m;
string dp[M + 1] = {{}};

void isZero(string &s)
{
    if (s.size() && s[0] == '0')
    {
        s = "0";
    }
}

bool cmp(string s0, string s1)
{
    isZero(s0);
    isZero(s1);
    if (s0.size() != s1.size())
    {
        return s0.size() < s1.size();
    }
    else
    {
        ll size = s0.size();
        for (ll i = 0; i < size; ++i)
        {
            if (s0[i] != s1[i])
            {
                return s0[i] < s1[i];
            }
        }
        return true;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> price[i];
    }
    cin >> m;

    for (ll i = n - 1; i >= 0; --i)
    {
        string si = to_string(i);
        for (ll p = price[i]; p <= m; ++p)
        {
            dp[p] = max(dp[p], dp[p - price[i]] + si, cmp);
        }
    }

    isZero(dp[m]);
    cout << dp[m] << "\n";

    return 0;
}