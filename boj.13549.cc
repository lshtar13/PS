#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MAX 100001

int main(void)
{
    int n, k;
    vector<int> mat(MAX, INT_MAX);
    scanf("%d %d", &n, &k);

    queue<int> q;
    q.push(n);
    mat[n] = 0;
    while(q.size())
    {
        int current = q.front(), next;
        q.pop();

        if((next = 2*current) < MAX && mat[current]<mat[next])
        {
            mat[next] = mat[current];
            q.push(next);
        }

        if((next = current + 1) < MAX && mat[current] + 1<mat[next])
        {
            mat[next] = mat[current] + 1;
            q.push(next);
        }
        
        if((next = current - 1) >= 0 && mat[current] + 1<mat[next])
        {
            mat[next] = mat[current] + 1;
            q.push(next);
        }
    }

    if(mat[k]  != INT_MAX)
        printf("%d", mat[k]);
    else
        printf("-1");

    return 0;
}