#include <bits/stdc++.h>

using namespace std;

u_int8_t nums[100];
u_int8_t ops[4];

int minv = INT32_MAX, maxv = INT32_MIN;

void calc(int pos, int n, int prev)
{
    if (pos == n - 1)
        minv = min(minv, prev), maxv = max(maxv, prev);
    else
    {
        for (int i = 0; i < 4; ++i)
            if (ops[i])
            {
                --ops[i];
                switch (i)
                {
                case 0:
                    calc(pos + 1, n, prev + nums[pos + 1]);
                    break;
                case 1:
                    calc(pos + 1, n, prev - nums[pos + 1]);
                    break;
                case 2:
                    calc(pos + 1, n, prev * nums[pos + 1]);
                    break;
                case 3:
                    calc(pos + 1, n, prev / nums[pos + 1]);
                    break;
                }
                ++ops[i];
            }
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        scanf("%hhd", &nums[i]);

    for (int i = 0; i < 4; ++i)
        scanf("%hhd", &ops[i]);

    calc(0, n, nums[0]);

    printf("%d\n%d", maxv, minv);
    return 0;
}