#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef const ll cll;
typedef priority_queue<ll> pqll;
typedef priority_queue<pll> pqpll;

cll MAX_N = 1e5;
ll n, root, parent[MAX_N] = {}, cords[MAX_N] = {};
pll child[MAX_N] = {}, levels[MAX_N] = {};

ll calc(ll org, ll node, ll level)
{
    ll result = 0;
    if(node == -1)
    {
        return result;
    }
    result += calc(org, child[node].first, level+1) + 1;
    result += calc(cords[node] = org + result, child[node].second, level+1);
    levels[level].first = min(levels[level].first, cords[node]);
    levels[level].second = max(levels[level].second, cords[node]);
    return result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for(ll node, lchild, rchild, i = 0; i<n; ++i)
    {
        cin>>node>>child[node].first>>child[node].second;
        if(child[node].first>0)
        {
            parent[child[node].first] = node;
        }
        
        if(child[node].second>0)
        {
            parent[child[node].second] = node;
        }
        levels[i].first = LLONG_MAX;
        levels[i].second = 0;
    }

    for(ll i = 1; i<=n; ++i)
    {
        if(parent[i] == 0)
        {
            root = i;
            break;
        }
    }

    // cout<<calc(0, root, 0)<<"\n";
    calc(0, root, 0);

    ll resultLevel = 1, resultWidth = 1;
    for(ll width, level = 1; levels[level].second; ++level)
    {
        if((width = levels[level].second - levels[level].first + 1) > resultWidth)
        {
            resultLevel = level + 1, resultWidth = width;
        }
    }

    cout<<resultLevel<<" "<<resultWidth<<"\n";

    return 0;
}