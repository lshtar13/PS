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
ll preSum[N + 1] = {};
string str;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str;
    for (ll i = 0; i < str.size(); ++i)
    {
        if (c == '(')
        {
            preSum[i + 1] = preSum[i] + 1;
        }
        else
        {
            preSum[i + 1] = preSum[i] - 1;
        }
    }

    if (abs(preSum[str.size() - 1]) != 1)
    {
        cout << 0;
        goto END;
    }

    

END:

    return 0;
}