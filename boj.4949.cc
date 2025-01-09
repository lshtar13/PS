#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    while (true)
    {
        char str[101];
        // scanf("%s", str);
        cin.getline(str, 101);

        if (!strcmp(str, "."))
            break;

        vector<char> stack;
        for (int i = 0; str[i]; ++i)
        {
            switch (str[i])
            {
            case '(':
                stack.push_back('(');
                break;
            case ')':
                if (stack.size() == 0 || stack.back() != '(')
                {
                    printf("no\n");
                    goto exit;
                }
                else
                    stack.pop_back();
                break;
            case '[':
                stack.push_back('[');
                break;
            case ']':
                if (stack.size() == 0 || stack.back() != '[')
                {
                    printf("no\n");
                    goto exit;
                }
                else
                    stack.pop_back();
                break;
            }
        }

        if (stack.size())
            printf("no\n");
        else
            printf("yes\n");
    exit:
        0;
    }
    return 0;
}