#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int find(vector<vector<int>> &dp, int node, int included, int parent,
        vector<vector<int>> &edges)
{
    if(dp[node][included] != -1)
    {
        return dp[node][included];
    }

    int result = included;

    for(auto child: edges[node])
    {
        if(child == parent)
        {
            continue;
        }

        if(!included)
        {
            result += find(dp, child, 1, node, edges);
        }
        else
        {
            result += min(find(dp, child, 1, node, edges),
                            find(dp, child, 0, node, edges));
        }
    }

    return dp[node][included] = result;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> edges(n);
    for(int i = 0, u, v; i<n-1; ++i)
    {
        cin>>u>>v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    int root = 0;
    vector<vector<int>> dp(n, vector<int>(2, -1));

    cout<<min(find(dp, root, 0, -1, edges), find(dp, root, 1, -1, edges));
    return 0;
}