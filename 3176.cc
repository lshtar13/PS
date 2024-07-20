#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_STEP = 12, MAX_NODE = 100001;
int k, n, parent[MAX_STEP+1][MAX_NODE+1] = {{0}},
    minCost[MAX_STEP+1][MAX_NODE+1] = {{0}}, 
    maxCost[MAX_STEP+1][MAX_NODE+1] = {{0}}, 
    depth[MAX_NODE+1] = {0}, minResult, maxResult;

void fill0(vector<vector<pair<int, int>>>edges, 
            int node, int _parent, int stage)
{
    for(auto p: edges[node])
    {
        int child = p.first, cost = p.second;
        if(child!=_parent)
        {
            parent[0][child] = node;
            minCost[0][child] = maxCost[0][child] = cost;
            fill0(edges, child, node, stage+1);
        }
    }
    depth[node] = stage;
}

void fill1(void)
{
    for(int step = 1; step<=MAX_STEP; ++step)
    {
        for(int i = 1; i<=n; ++i)
        {
            parent[step][i] = parent[step-1][parent[step-1][i]];
            minCost[step][i] = min(minCost[step-1][i],
                                minCost[step-1][parent[step-1][i]]);
            maxCost[step][i] = max(maxCost[step-1][i],
                                maxCost[step-1][parent[step-1][i]]);
        }
    }
}

int queryParent(int idx, int n)
{
    for(int i = MAX_STEP; i>=0; --i)
    {
        if(n&(1<<i))
        {
            maxResult = max(maxResult, maxCost[i][idx]);
            minResult = min(minResult, minCost[i][idx]);
            idx = parent[i][idx];
        }
    }

    return idx;
}

void find(int a, int b)
{
    int depthA = depth[a], depthB = depth[b],
        start = 0, end = min(depthA, depthB), mid;
    maxResult = 0, minResult = INT_MAX;
    if(!depthA)
    {
        queryParent(b, depthB);
    }
    else if(!depthB)
    {
        queryParent(a, depthA);
    }
    for(mid = (start+end)/2; start<end; mid = (start+end)/2)
    {
        int _a = queryParent(a, depthA-mid), _b = queryParent(b, depthB-mid);
        if(_a == _b)
        {
            start = mid+1;
        }
        else
        {
            end = mid;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    
    vector<vector<pair<int, int>>> edges(n+1);
    for(int i = 0, a, b, c; i<n-1; ++i)
    {
        cin>>a>>b>>c;
        edges[a].push_back(make_pair(b, c));
        edges[b].push_back(make_pair(a, c));
    }

    fill0(edges, 1, 0, 0);
    fill1();

    cin>>k;
    for(int i = 0, d, e; i<k; ++i)
    {
        cin>>d>>e;
        find(d, e);
        cout<<minResult<<" "<<maxResult<<"\n";
    }

    return 0;
}