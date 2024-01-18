#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char s[51];
    scanf("%s", s);
    int nums[51] = {0}, ops[51] = {0}, numlen = 0, num = 0;
    for (int i = 0, len = strlen(s); i < len; ++i)
        switch (s[i])
        {
        case '+':
            nums[numlen] = num, ops[numlen++] = 0, num = 0;
            break;
        case '-':
            nums[numlen] = num, ops[numlen++] = 1, num = 0;
            break;
        default:
            num *= 10, num += s[i] - '0';
            // printf("%d\n", num);
        }
    nums[numlen++] = num;

    int result = 0;
    for (int i = 0, minus = 0; i < numlen; ++i)
        result = minus ? result - nums[i] : result + nums[i], minus = minus ? 1 : ops[i] == 1;
    printf("%d", result);
    return 0;
}