#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string solve(void)
{
    int v,e;
    scanf("%d %d", &v, &e);

    vector<int> mat(v, 0);
    vector<vector<int>> edges(v);
    for(int i = 0, a, b; i<e; ++i)
    {
        scanf("%d %d", &a, &b);
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    queue<int> q;
    for(int i = 0; i<v; ++i)
    {
        if(mat[i])
        {
            continue;
        }

        q.push(i);
        mat[i] = 1;
        while(q.size())
        {
            int vertex = q.front();
            q.pop();

            for(auto av: edges[vertex])
            {
                if(mat[av] == mat[vertex])
                {
                    return "NO";
                }
                if(mat[av])
                {
                    continue;
                }
                mat[av] = -mat[vertex];
                q.push(av);
            }
        }
    }

    return "YES";
}

int main(void)
{
    int k;
    scanf("%d", &k);

    while(k--)
    {
        cout<<solve()<<endl;
    }

    return 0;
}