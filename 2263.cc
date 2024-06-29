#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int inorder[100001] = {0}, postorder[100001] = {0};

int destruct(vector<pair<int, int>> &bt, 
                int start_i, int end_i,
                int start_p, int end_p)
{
    // int dum;
    // scanf("%dum", &dum);
    if(start_i > end_i)
    {
        return -1;
    }

    int parent = postorder[end_p], gap = 0;
    for(gap = 0; inorder[start_i + gap] != parent; ++gap)
        ;
    // printf("parent %d parent_idx %d (%d, %d) (%d, %d)\n",
    // parent, start_i + gap, start_i, end_i, start_p, end_p);

    // exit(0);

    bt[parent] = make_pair(
        destruct(bt, start_i, start_i + gap-1, start_p, start_p + gap -1),
        destruct(bt, start_i + gap +1, end_i, start_p + gap, end_p - 1));

    return parent;
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i<n; ++i)
    {
        scanf("%d", &inorder[i]);
    }
    
    for(int i = 0; i<n; ++i)
    {
        scanf("%d", &postorder[i]);
    }
    
    vector<pair<int, int>> bt(n+1);

    // for(int i = 1; i<=n; ++i)
    // {
    //     printf("%d : (%d, %d)\n", i, bt[i].first, bt[i].second);
    // }

    stack<int> s;
    s.push(destruct(bt,0,n-1,0,n-1));

    while(!s.empty())
    {
        int top = s.top();
        if(top == -1)
        {
            s.pop();
        }
        else
        {
            printf("%d ",top);
            s.pop();
            s.push(bt[top].second);
            s.push(bt[top].first);
        }
    }

    return 0;
}