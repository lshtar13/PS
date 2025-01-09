#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> edge;

int find(vector<int> &parents, int v)
{
    return parents[v] = parents[v] == v ? v : find(parents, parents[v]);
}

bool merge(vector<int> &parents, int v0, int v1)
{
    int root0 = find(parents, v0), root1 = find(parents, v1);
    if(root0==root1)
    {
        return false;
    }
    else
    {
        parents[root0] = root1;
        return true;
    }
}

void solve(int m, int n)
{
    vector<int> parents(m);
    for(int i = 0; i<m; ++i)
    {
        parents[i] = i;
    }
    
    int total = 0;
    priority_queue<edge, vector<edge>, greater<edge>> edges;
    for(int i = 0, x, y, z; i<n; ++i)
    {
        cin>>x>>y>>z;
        edges.push(make_pair(z, make_pair(x, y)));
        total += z;
    }

    int weights = 0;
    while(!edges.empty())
    {
        edge me = edges.top();
        edges.pop();

        if(merge(parents, me.second.first, me.second.second))
        {
            weights += me.first;
        }
    }
    cout<<total-weights<<"\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int m, n; cin>>m>>n && m && n; solve(m, n))
        ;

    return 0;
}