#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<int> stack;
    while (n--)
    {
        int cmd;
        scanf("%d", &cmd);

        switch (cmd)
        {
        case 1:
            int x;
            scanf("%d", &x);
            stack.push_back(x);
            break;
        case 2:
            if (stack.size())
            {
                printf("%d\n", stack.back());
                stack.pop_back();
            }
            else
                printf("%d\n", -1);
            break;
        case 3:
            printf("%ld\n", stack.size());
            break;
        case 4:
            if (stack.size())
                printf("%d\n", 0);
            else
                printf("%d\n", 1);
            break;
        case 5:
            if (stack.size())
                printf("%d\n", stack.back());
            else
                printf("%d\n", -1);
            break;
        }
    }
    return 0;
}