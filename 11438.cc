#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, sparse_table[17][100001] = {{0}}, depth[100001] = {0};

void fill0(vector<vector<int>> &edges, int node, int parent, int stage)
{
    depth[node] = stage;
    for(auto c: edges[node])
    {
        if(c == parent)
        {
            continue;
        }
        sparse_table[0][c] = node;
        fill0(edges, c, node, stage + 1);
    }
}

int query(int idx, int n)
{
    for(int i = 16; i>=0; --i)
    {
        if(n&(1<<i))
        {
            idx = sparse_table[i][idx];
        }
    }

    return idx;
}

int find(int a, int b)
{
    int depthA = depth[a], depthB = depth[b],
        start = 0, end = min(depthA, depthB), mid;
    for(mid = (start+end)/2; start<end; mid = (start+end)/2)
    {
        int _a = query(a, depthA-mid), _b = query(b, depthB-mid);
        if(_a == _b)
        {
            start = mid+1;
        }
        else
        {
            end = mid;
        }
    }

    // cout<<start<<" "<<end<<"\n";
    int _a = query(a, depthA-mid), _b = query(b, depthB-mid),
        result = depthB - start;
    if(_a != _b)
    {
        ++result;
    }
    return query(b, result);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 한쪽을 구한 다음 이분 탐색으로 찾기;
    cin>>n;
    vector<vector<int>> edges(n+1);
    for(int i = 0, a, b; i<n-1; ++i)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    fill0(edges, 1, 0, 0);
    
    for(int step = 1; (1<<step)<=n; ++step)
    {
        for(int i = 1; i<=n; ++i)
        {
            sparse_table[step][i] = sparse_table[step-1][
                                    sparse_table[step-1][i]
                                    ];
        }
    }

    cin>>m;
    while(m--)
    {
        int a, b;
        cin>>a>>b;
        cout<<find(a, b)<<"\n";
    }

    return 0;
}