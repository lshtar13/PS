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

cll K = 62, N = 900, F = 5600;
ll k, n, f, mat[N][N] = {{}};
vvll edges(N);

bool search(vll &nodes, ll idx)
{
    if (nodes.size() == k)
    {
        for (auto &node : nodes)
        {
            cout << node + 1 << "\n";
        }
        return true;
    }
    else if (idx >= n)
    {
        return false;
    }

    bool isOk = true;
    for (auto &node : nodes)
    {
        if (!mat[node][idx])
        {
            isOk = false;
            break;
        }
    }
    if (isOk)
    {
        nodes.emplace_back(idx);
        if (search(nodes, idx + 1))
        {
            return true;
        }
        nodes.pop_back();
    }

    if (search(nodes, idx + 1))
    {
        return true;
    }

    return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n >> f;
    for (ll f0, f1, i = 0; i < f; ++i)
    {
        cin >> f0 >> f1;
        --f0, --f1;
        mat[f0][f1] = mat[f1][f0] = 1;
    }

    vll nodes;
    if (!search(nodes, 0))
    {
        cout << -1;
    }

    return 0;
}