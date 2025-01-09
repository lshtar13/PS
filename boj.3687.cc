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

cll N = 100, num[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
ll n;
string dp0[N + 1] = {"-1", "-1", "1", "7", "11", "71", "111", "711"},
               dp1[N + 1] = {"-1", "-1", "1", "7", "4", "2", "6", "8"};

string cmpStr(string str0, string str1, bool isMax)
{
    if (str0 == "-1")
    {
        return str1;
    }
    else if (str1 == "-1")
    {
        return str0;
    }
    else if (str0.size() > str1.size())
    {
        return isMax ? str0 : str1;
    }
    else if (str0.size() < str1.size())
    {
        return isMax ? str1 : str0;
    }
    else if (str0 > str1)
    {
        return isMax ? str0 : str1;
    }
    else
    {
        return isMax ? str1 : str0;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (ll i = 8; i <= N; ++i)
    {
        dp0[i] = "-1";
        for (ll k = 0; k < 10; ++k)
        {
            dp0[i] = cmpStr(dp0[i], dp0[i - num[k]] + to_string(k), true);
        }
    }

    for (ll i = 8; i <= N; ++i)
    {
        dp1[i] = "-1";
        for (ll k = 0; k < 10; ++k)
        {
            dp1[i] = cmpStr(dp1[i], dp1[i - num[k]] + to_string(k), false);
        }
    }

    cin >> n;
    for (ll k, i = 0; i < n; ++i)
    {
        cin >> k;
        cout << dp1[k] << " " << dp0[k] << "\n";
    }

    return 0;
}