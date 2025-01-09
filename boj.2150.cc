#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_V = 10000;
int v, e, ngroup = 0;
char visited[MAX_V] = {0}, edges[MAX_V][MAX_V] = {{0}};
vector<vector<int>> mat(v);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>v>>e;

    vector<int> parent(v, -1);
    vector<vector<int>> mat(v);
    for(int i = 0, a, b; i<e; ++i)
    {
        cin>>a>>b;
        --a, --b;
        mat[a].push_back(b);
    }

    int nresult = 0;
    vector<int> result; 
    stack<int> s, dfs;
    dfs.push(0);
    while(!dfs.empty())
    {
        int idx = dfs.top();
        dfs.pop();

        if(parent[idx]<0)
        {
            parent[idx] = idx;
            s.push(idx);
        }
        else
        {
            while(parent)
            ++nresult;
        }
    }

    return 0;
}