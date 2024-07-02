#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<double, pair<int, int>> edge;

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

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> gods(n);
    priority_queue<edge, vector<edge>, greater<edge>> edges;
    vector<int> parents(n);
    for(int i = 0; i<n; ++i)
    {
        parents[i] = i;
    }

    for(int i = 0, x, y; i<n; ++i)
    {
        cin>>x>>y;
        gods[i] = make_pair(x, y);
        for(int l = 0; l<i; ++l)
        { 
            double dx, dy, d;
            dx = x - gods[l].first, dy = y - gods[l].second;
            d = pow(dx, 2) + pow(dy, 2);
            d = sqrt(d);
            edges.push(make_pair(d, make_pair(i, l)));
        }
    }

    for(int i = 0, a, b; i<m; ++i)
    {
       cin>>a>>b;
       --a, --b; 
       merge(parents, a, b);
    }

    double distance = 0;
    while(!edges.empty())
    {
        edge me = edges.top();
        edges.pop();
        
        int v0 = me.second.first, v1 = me.second.second;
        if(merge(parents, v0, v1))
        {
            distance += me.first; 
        }
    }

    cout<<fixed;
    cout.precision(2);
    cout<<distance;

    return 0;
}