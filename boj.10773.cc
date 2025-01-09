#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int k;
    scanf("%d", &k);

    vector<int> stack;
    while (k--)
    {
        int num;
        scanf("%d", &num);

        if (num)
            stack.push_back(num);
        else
            stack.pop_back();
    }

    int result = 0;
    for (auto &x : stack)
        result += x;
    printf("%d", result);
    return 0;
}