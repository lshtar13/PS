#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 987654321

int main(void)
{
    int n, k;
    vector<pair<int, int>> mat(100001, make_pair(INF,-1));
    scanf("%d %d", &n, &k);
    queue<int> q;
    mat[n].first = 0;
    q.push(n);
    while(!q.empty())
    {
        int idx = q.front(), next;
        int cost = mat[idx].first, pre = mat[idx].second;
        q.pop();

        if((next = idx-1)>=0 && mat[next].first > cost+1)
        {
            mat[next].first = cost+1;
            mat[next].second = idx;
            q.push(next);
        }
        
        if((next = idx+1)<=100000 && mat[next].first > cost+1)
        {
            mat[next].first = cost+1;
            mat[next].second = idx;
            q.push(next);
        }
        
        if((next = idx*2)<=100000 && mat[next].first > cost+1)
        {
            mat[next].first = cost+1;
            mat[next].second = idx;
            q.push(next);
        }
    }

    printf("%d\n",mat[k].first);

    stack<int> s;
    int idx = k;
    while(true)
    {
        if(idx < 0)
        {
            break;
        }
        s.push(idx);
        idx = mat[idx].second;
    }

    while(!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }

    return 0;
}