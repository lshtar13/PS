#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> edge;

int find(vector<int> &parents, int n)
{
    return parents[n] = parents[n] == n ? n : find(parents, parents[n]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;

    vector<int> parents(v+1);
    for(int i = 0; i<v+1; ++i)
    {
        parents[i] = i;
    }

    priority_queue<edge, vector<edge>, greater<edge>> edges;
    for(int i = 0, a, b, c; i<e; ++i)
    {
        cin>>a>>b>>c;
        edges.push(make_pair(c,make_pair(a, b)));
    }

    ll weights=0;
    while(!edges.empty())
    {
        edge me = edges.top();
        edges.pop();

        int v0 = me.second.first, v1 = me.second.second, w = me.first,
            root0 = find(parents, v0), root1 = find(parents, v1);
        if(root0 == root1)
        {
            continue;
        }

        parents[root0] = root1;
        weights += w;
    }

    printf("%lld", weights);
    return 0;
}