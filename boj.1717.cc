#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int findRoot(vector<int> &set, int n)
{
    return set[n] = (set[n]==n ? n : findRoot(set, set[n]));
}

int main(void)
{
    int n, m; 
    scanf("%d %d", &n, &m);

    vector<int> set(n+1);
    for(int i = 0; i<=n; ++i)
    {
        set[i] = i;
    }

    for(int type, a, b; scanf("%d %d %d", &type, &a, &b)!=EOF;)
    {
        int rootA = findRoot(set, a), rootB=findRoot(set, b);
        if(!type)
        {
            if(rootA == rootB)
            {
                continue;
            }

            set[rootB] = rootA;
        }
        else
        {
            if(rootA == rootB)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}