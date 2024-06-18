#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void printMat(vector<int> &mat, int n, int m)
{
    for(int i = 0; i<n; ++i)
    {
        for(int l = 0; l<m; ++l)
        {
            printf("%d ", mat[i*m + l]);
        }
        printf("\n");
    }
}

void bfs(vector<int> &mat, int start, int n, int m)
{
    queue<int> q;
    mat[start] = 1;
    q.push(start);
    while(q.size())
    {
        int idx = q.front(), i = idx/m, l = idx%m, next;
        q.pop();
        // printf("%d\n",idx);
        if(i+1<n && !mat[next = (i+1)*m + l])
        {
            q.push(next);
            mat[next] = mat[idx] + 1;
        }
        if(i-1>-1 && !mat[next = (i-1)*m + l])
        {
            q.push(next);
            mat[next] = mat[idx] + 1;
        }
        if(l+1<m && !mat[next = i*m + l+1])
        {
            q.push(next);
            mat[next] = mat[idx] + 1;
        }
        if(l-1>-1 && !mat[next = i*m + l-1])
        {
            q.push(next);
            mat[next] = mat[idx] + 1;
        }
    }
}

int main(void)
{
    int n,m;
    scanf("%d %d", &n, &m);

    vector<int> mat0(n*m), mat1(n*m), barriers;
    for(int i = 0; i<n; ++i)
    {
        string nums;
        cin>>nums;
        for(int l = 0; l<m; ++l)
        {
            mat1[i*m + l] = mat0[i*m + l] = (nums[l] - '0' ? -1 : 0);
            if(nums[l] == '1')
            {
                barriers.push_back(i*m + l);
            }
        }
    }

    bfs(mat0, 0, n, m);
    // printMat(mat0,n,m);

    // printf("\n");

    bfs(mat1, n*m-1, n, m);
    // printMat(mat1,n,m);

    int result = INT_MAX;
    for(auto idx: barriers)
    {
        int i = idx/m, l = idx%m;
        if(i+1<n && i-1>-1)
        {
            if(mat0[(i+1)*m + l]>0 && mat1[(i-1)*m + l]>0)
            {
                // printf("%d %d\n", i, l);
                result = min(result, mat0[(i+1)*m + l] + mat1[(i-1)*m + l]);
            }

            if(mat1[(i+1)*m + l]>0 && mat0[(i-1)*m + l]>0)
            {
                // printf("%d %d\n", i, l);
                result = min(result, mat1[(i+1)*m + l] + mat0[(i-1)*m + l]);
            }
        }

        if(l+1<m && l-1>-1)
        {
            if(mat0[i*m + l+1]>0 && mat1[i*m + l-1]>0)
            {
                // printf("%d %d\n", i, l);
                result = min(result, mat0[i*m + l+1] + mat1[i*m + l-1]);
            }
            
            if(mat1[i*m + l+1]>0 && mat0[i*m + l-1]>0)
            {
                // printf("%d %d\n", i, l);
                result = min(result, mat1[i*m + l+1] + mat0[i*m + l-1]);
            }
        }
    }

    if(mat0[n*m-1]>0)
    {
        result = min(result, mat0[n*m-1]-1);
    }

    if(result == INT_MAX)
    {
        printf("-1");
    }
    else
    {
        printf("%d",result+1);
    }

    return 0;
}