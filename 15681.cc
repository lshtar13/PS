#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int subtree(vector<vector<int>> &edges, vector<int> &memo, 
            int node, int parent)
{
    int result = 1;
    for(auto child: edges[node])
    {
        if(child != parent)
        {
            result += subtree(edges, memo, child, node);
        }
    }

    return memo[node] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, r, q;
    cin>>n>>r>>q;

    vector<int> memo(n);
    vector<vector<int>> edges(n);
    for(int i = 0, u, v; i<n-1; ++i)
    {
        cin>>u>>v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    subtree(edges, memo, --r, -1);

    for(int i = 0, u; i<q; ++i)
    {
        cin>>u;
        cout<<memo[--u]<<"\n";
    }

    return 0;
}