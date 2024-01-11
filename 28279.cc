#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    deque<int> dq;
    while (n--)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
            int x;
        case 1:
            scanf("%d", &x);
            dq.push_front(x);
            break;
        case 2:
            scanf("%d", &x);
            dq.push_back(x);
            break;
        case 3:
            if (dq.size())
            {
                printf("%d\n", dq.front());
                dq.pop_front();
            }
            else
                printf("%d\n", -1);
            break;
        case 4:
            if (dq.size())
            {
                printf("%d\n", dq.back());
                dq.pop_back();
            }
            else
                printf("%d\n", -1);
            break;
        case 5:
            printf("%ld\n", dq.size());
            break;
        case 6:
            printf("%d\n", dq.size() ? 0 : 1);
            break;
        case 7:
            printf("%d\n", dq.size() ? dq.front() : -1);
            break;
        case 8:
            printf("%d\n", dq.size() ? dq.back() : -1);
            break;
        }
    }
    return 0;
}