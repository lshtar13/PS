#include <bits/stdc++.h>

using namespace std;

bool search(vector<int> &nums, int tgt, int start, int end)
{
    if (start > end)
        return false;

    int mid = (start + end) / 2;
    if (nums[mid] == tgt)
        return true;
    else if (nums[mid] < tgt)
        return search(nums, tgt, mid + 1, end);
    else
        return search(nums, tgt, start, mid - 1);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<int> nums(n);
    for (auto &x : nums)
        scanf("%d", &x);

    sort(nums.begin(), nums.end());

    int m;
    scanf("%d", &m);
    for (int i = 0, x; i < m; ++i)
    {
        scanf("%d", &x);
        printf("%d ", search(nums, x, 0, n - 1) ? 1 : 0);
    }

    return 0;
}