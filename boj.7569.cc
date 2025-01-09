#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
    ll m,n,h;
    scanf("%lld %lld %lld", &m, &n, &h);

    vector<ll> mat(m*n*h);
    for(int i = 0; i<h; ++i)
    {
        for(int l = 0; l<n; ++l)
        {
            for(int j = 0; j<m; ++j)
            {
                scanf("%lld", &mat[i*m*n+l*m+j]);
            }
        }
    }

    queue<ll> q;
    for(int idx = 0; idx<n*m*h; ++idx)
    {
        if(mat[idx] == 1)
        {
            q.push(idx);
        }
    }
    ll result = 0;
    while(q.size())
    {
        ll idx = q.front(), i = idx/(m*n), l = (idx%(m*n))/m, j = idx%m, next;
        q.pop();

        if(i+1<h && mat[next = (i+1)*m*n + l*m + j] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(mat[next] = mat[idx] + 1, result);
                q.push(next);
            }
        }
        if(i-1>-1 && mat[next = (i-1)*m*n + l*m + j] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result ,mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
        if(l+1<n && mat[next = i*m*n + (l+1)*m + j] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result, mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
        if(l-1>-1 && mat[next = i*m*n + (l-1)*m + j] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result, mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
        if(j+1<m && mat[next = i*m*n + l*m + j+1] != -1)
        {
            if(!mat[next] || mat[idx]+1 < mat[next])
            {
                result = max(result, mat[next] = mat[idx] + 1);
                q.push(next);
            }
        }
        if(j-1>-1 && mat[next = i*m*n + l*m + j-1] != -1)
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

    for(ll idx = 0; idx<m*n*h; ++idx)
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