#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int find(vector<vector<int>> &dp, int node, int included, int parent,
        vector<int> &weights, vector<vector<int>> &edges)
{
    if(dp[node][included] != -1)
    {
        return dp[node][included];
    }

    int result = included ? weights[node] : 0;

    for(auto child: edges[node])
    {
        if(child == parent)
        {
            continue;
        }

        if(included)
        {
            result += find(dp, child, 0, node, weights, edges);
        }
        else
        {
            result += max(find(dp, child, 1, node, weights, edges),
                            find(dp, child, 0, node, weights, edges));
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
    vector<int> weights(n);
    for(int i = 0; i<n; ++i)
    {
        cin>>weights[i];
    }

    vector<vector<int>> edges(n);
    for(int i = 0, u, v; i<n-1; ++i)
    {
        cin>>u>>v;
        --u, --v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(2,-1));
    int root = 0, result0 = find(dp, root, 0, -1, weights, edges),
        result1 = find(dp, root, 1, -1, weights, edges);
    
    cout<<max(result0, result1);
    return 0;
}