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

cll N = 20, directions[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
ll n, ssize = 2, mat[N][N] = {{}}, result = 0, past = 0, check[N][N] = {{}};
pll shark;

bool isValid(ll i, ll l)
{
    return i >= 0 && i < n && l >= 0 && l < n;
}

struct cmp
{
    bool operator()(pll a, pll b)
    {
        ll distA = check[a.first][a.second], distB = check[b.first][b.second];

        if (distA == distB)
        {
            if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first > b.first;
        }
        return distA > distB;
    }
};

void search(void)
{
    memset(check, 0, sizeof(check));
    priority_queue<pll, vector<pll>, cmp> pq;
    pq.push(shark);
    check[shark.first][shark.second] = 1;
    for (ll i, l; !pq.empty();)
    {
        i = pq.top().first, l = pq.top().second;
        pq.pop();
        if (mat[i][l] < ssize && mat[i][l])
        {
            result += check[i][l] - 1;
            shark = make_pair(i, l), mat[i][l] = 0;
            if (++past == ssize)
            {
                ++ssize, past = 0;
            }
            return search();
        }

        for (auto &d : directions)
        {
            ll _i = i + d[0], _l = l + d[1];
            if (check[_i][_l] || !isValid(_i, _l))
            {
                continue;
            }

            if (mat[_i][_l] <= ssize)
            {
                check[_i][_l] = check[i][l] + 1;
                pq.push(make_pair(_i, _l));
            }
        }
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
        for (ll l = 0; l < n; ++l)
        {
            cin >> mat[i][l];
            if (mat[i][l] == 9)
            {
                shark = make_pair(i, l);
                mat[i][l] = 0;
            }
        }
    }

    search();

    cout << result << "\n";

    return 0;
}