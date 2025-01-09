#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    int n, m, mat[101] = {0};
    scanf("%d %d", &n, &m);

    map<int, int> transport;
    for(int i = 0, x, y; i<n; ++i)
    {
        scanf("%d %d", &x, &y);
        transport[x] = y;
    }
    for(int i = 0, u, v; i<m; ++i)
    {
        scanf("%d %d", &u, &v);
        transport[u] = v;
    }

    queue<int> q;
    q.push(1);
    while(q.size())
    {
        int num = q.front(), next;
        q.pop();

        if(next = transport[num])
        {
            if(!mat[next] || mat[num] < mat[next])
            {
                mat[next] = mat[num];
                q.push(next);
            }
        }
        else
        {
            for(int i = 1; i<=6; ++i)
            {
                if((next = num+i)<=100 && (!mat[next] || mat[num]+1 < mat[next]))
                {
                    mat[next] = mat[num]+1;
                    q.push(next);
                }
            }
        }
    }

    printf("%d", mat[100]);

    return 0;
}