#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<double, pair<int, int>> edge;

int find(vector<int> &parents, int n)
{
    return parents[n] = parents[n] == n ? n : find(parents, parents[n]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> parents(n);
    vector<pair<double, double>> stars(n);
    priority_queue<edge, vector<edge>, greater<edge>> edges;
    for(int i = 0; i<n; ++i)
    {
        double a, b;
        cin>>a>>b;
        stars[i] = make_pair(a, b);
        parents[i] = i;
        for(int l = 0; l<i; ++l)
        {
            double _a = stars[l].first, _b = stars[l].second;
            double distance = sqrt((a-_a)*(a-_a) + (b-_b)*(b-_b));
            edges.push(make_pair(distance, make_pair(i, l)));
        }
    }

    double distance = 0;
    while(!edges.empty())
    {
        edge me = edges.top();
        edges.pop();
        int v0 = me.second.first, v1 = me.second.second,
            root0 = find(parents, v0), root1 = find(parents, v1);
        double w = round(me.first*100)/100;

        if(root0 == root1)
        {
            continue;
        }
        // cout<<" "<<v0<<" "<<v1<<" "<<w<<"\n";
        parents[root0] = root1;
        distance += w;
        distance = round(distance*100)/100;
    }

    cout<<round(distance*100)/100;

    return 0;
}