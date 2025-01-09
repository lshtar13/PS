#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, nums[10001] = {0};
    scanf("%d", &n);
    while (n--)
    {
        int num;
        scanf("%d", &num);
        ++nums[num];
    }

    for (int i = 0; i < 10001; ++i)
    {
        if (nums[i])
        {
            for (int l = 0; l < nums[i]; ++l)
                printf("%d\n", i);
        }
    }

    return 0;
}