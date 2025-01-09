#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    queue<int> q;
    while (n--)
    {
        char cmd[10];
        scanf("%s", cmd);

        if (!strcmp(cmd, "push"))
        {
            int x;
            scanf("%d", &x);

            q.push(x);
        }
        else if (!strcmp(cmd, "pop"))
        {
            if (q.size() == 0)
                printf("%d\n", -1);
            else
            {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (!strcmp(cmd, "size"))
        {
            printf("%ld\n", q.size());
        }
        else if (!strcmp(cmd, "empty"))
        {
            printf("%d\n", q.size() ? 0 : 1);
        }
        else if (!strcmp(cmd, "front"))
        {
            if (q.size() == 0)
                printf("%d\n", -1);
            else
            {
                printf("%d\n", q.front());
            }
        }
        else if (!strcmp(cmd, "back"))
        {
            if (q.size() == 0)
                printf("%d\n", -1);
            else
            {
                printf("%d\n", q.back());
            }
        }
    }
    return 0;
}