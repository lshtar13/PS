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
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
#define FOR1(a, A) for (ll a = 0; a < A; ++a)
#define FOR2(a, b, A, B)       \
    for (ll a = 0; a < A; ++a) \
        for (ll b = 0; b < B; ++b)

cll L = 1e6;
ll length, pi[L] = {};
char tgt[L + 1] = {};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> length >> tgt;
    for (ll i = 1, prv; i < length; ++i)
    {
        prv = pi[i - 1];
        while (prv && tgt[i] != tgt[prv])
        {
            prv = pi[prv - 1];
        }

        if (tgt[i] == tgt[prv])
        {
            pi[i] = prv + 1;
        }
    }

    cout << length - pi[length - 1] << "\n";

    return 0;
}