#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_NODE = 200001,
            MAX_STEP = 20;
int parent[MAX_STEP][MAX_NODE];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin>>m;
    // vector<vector<int>> parent(MAX_STEP, vector<int>(m+1));
    for(int i = 1, p; i<=m; ++i)
    {
        cin>>p;
        parent[0][i] = p;
    }

    for(int step = 1; step<MAX_STEP; ++step)
    {
        for(int c = 1; c<=m; ++c)
        {
            parent[step][c] = parent[step-1][parent[step-1][c]];
        }
    }

    int q, n, x, result;
    cin>>q;
    while(q--)
    {
        cin>>n>>x;
        result = x;
        for(int _n = n, step; _n > 0; _n -= pow(2, step))
        {
            step = log2(_n);
            result = parent[step][result];
        }

        cout<<result<<"\n";
    }

    return 0;
}