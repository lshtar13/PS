#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        char str[51];
        scanf("%s", str);

        vector<bool> stack;
        for (int i = 0; str[i]; ++i)
            switch (str[i])
            {
            case '(':
                stack.push_back(true);
                break;
            case ')':
                if (stack.size() == 0)
                {
                    printf("NO\n");
                    goto exit;
                }
                else
                    stack.pop_back();
            }
        if (stack.size() == 0)
            printf("YES\n");
        else
            printf("NO\n");
    exit:
        0;
    }
    return 0;
}