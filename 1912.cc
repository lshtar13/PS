#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int arr[100001] = {0};

    int n, num, pre, result;
    scanf("%d %d", &n, &num);
    result = pre = num;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &num);
        pre = max(pre + num, num);
        result = max(result, pre);
    }

    printf("%d", result);
    return 0;
}