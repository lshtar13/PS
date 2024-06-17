#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll m,n;
    scanf("%lld %lld", &m, &n);

    vector<ll> mat(m*n);
    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<m; ++l)
        {
            scanf("%lld", &mat[i*m+l]);
        }
    }

    queue<ll> q;
    for(int idx = 0; idx<n*m; ++idx)
    {
        if(mat[idx] == 1)
        {
            q.push(idx);
        }
    }
    ll result = 0;
    while(q.size())
    {
        ll idx = q.front(), i = idx/m, l = idx%m, next;
        q.pop();

        if(i+1<n && mat[next = (i+1)*m + l] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(mat[next] = mat[idx] + 1, result);
                q.push(next);
            }
        }
        if(l+1<m && mat[next = i*m + l+1] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result ,mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
        if(i-1>-1 && mat[next = (i-1)*m + l] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result, mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
        if(l-1>-1 && mat[next = i*m + l-1] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result, mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
    }

    // for(int i = 0; i<n; ++i)
    // {
    //     for(int l = 0; l<m; ++l)
    //     {
    //         printf("%lld ", mat[i*m+l]);
    //     }
    //     printf("\n");
    // }

    for(ll idx = 0; idx<m*n; ++idx)
    {
        if(!mat[idx])
        {
            printf("-1");
            return 0;
        }
    }
    printf("%lld", result ? result - 1 : 0);

    return 0;
}