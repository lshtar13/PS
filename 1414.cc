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
typedef pair<ll, pll> pllpll;

cll N = 50;
ll n, totalLength = 0, parents[N + 1] = {};
priority_queue<pllpll, vector<pllpll>, greater<pllpll>> edges;

ll findParent(ll node)
{
    if (parents[node] == node)
    {
        return node;
    }
    else
    {
        return parents[node] = findParent(parents[node]);
    }
}

void merge(ll node0, ll node1)
{
    parents[findParent(node1)] = findParent(node0);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin.ignore();
        parents[i] = i;
        for (ll w, l = 0; l < n; ++l)
        {
            char c;
            cin >> c;
            if (c == '0')
            {
                continue;
            }
            else if (c >= 'a' && c <= 'z')
            {
                edges.push(make_pair(w = c - 'a' + 1, make_pair(i, l)));
            }
            else
            {
                edges.push(make_pair(w = c - 'A' + 27, make_pair(i, l)));
            }
            totalLength += w;
        }
    }

    ll rest = totalLength;
    while (!edges.empty())
    {
        ll w = edges.top().first, i = edges.top().second.first, l = edges.top().second.second;
        edges.pop();
        if (findParent(i) == findParent(l))
        {
            continue;
        }

        rest -= w;
        merge(i, l);
        // cout << i << " " << l << " : " << w << "\n";
    }

    ll root = findParent(0);
    for (ll i = 1; i < n; ++i)
    {
        if (root != findParent(i))
        {
            cout << "-1\n";
            goto END;
        }
    }
    cout << rest << "\n";

END:

    return 0;
}