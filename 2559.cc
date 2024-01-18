#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k, result = 0;
    scanf("%d %d", &n, &k);

    int sum[100000] = {0}, nums[100000] = {0};
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &nums[i]);
        sum[0] += nums[i];
    }

    result = sum[0];
    for (int i = k; i < n; ++i)
    {
        scanf("%d", &nums[i]);
        result = max(sum[i - k + 1] = sum[i - k] + nums[i] - nums[i - k], result);
    }

    printf("%d", result);
    return 0;
}