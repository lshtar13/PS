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

cll N = 100, K = 100, L = 100, dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
ll n, k, l, dir, cur;
unordered_set<ll> apples, snakes;

bool isValid(ll a, ll b)
{
    return a >= 0 && a < n && b >= 0 && b < n && (snakes.find(a * n + b) == snakes.end());
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (ll a, b, i = 0; i < k; ++i)
    {
        cin >> a >> b;
        apples.insert(n * (a - 1) + b - 1);
    }

    cin >> l;
    dir = cur = 0;
    qll q;
    q.push(0);
    snakes.insert(0);
    ll x, a = 0, b = 0, next;
    char c;
    while (true)
    {
        if (l--)
        {
            cin >> x >> c;
        }
        else
        {
            x = LLONG_MAX;
        }
        while (cur < x)
        {
            ++cur, a += dirs[dir][0], b += dirs[dir][1];
            if (!isValid(a, b))
            {
                goto END;
            }
            next = a * n + b;
            q.push(next);
            snakes.insert(next);
            if (apples.find(next) != apples.end())
            {
                apples.erase(next);
            }
            else
            {
                snakes.erase(q.front());
                q.pop();
            }
        }
        dir = (dir + (c == 'D' ? 1 : 3)) % 4;
    }

END:
    cout << cur << "\n";

    return 0;
}