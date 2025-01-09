// #include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>

int swp;

void quicksort(int nums[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = nums[start];
    int low = start + 1, high = end;
    while (low <= high)
    {
        if (nums[low] <= pivot)
            ++low;
        if (nums[high] >= pivot)
            --high;

        if (nums[low] <= pivot && nums[high] >= pivot)
            swp = nums[low], nums[low] = nums[high], nums[high] = swp;
    }

    nums[start] = nums[high], nums[high] = pivot;
    quicksort(nums, start, high - 1);
    quicksort(nums, high + 1, end);
}

void mergesort(int nums[], int start, int end)
{
    if (start == end)
        return;

    if (start + 1 == end)
    {
        if (nums[start] > nums[end])
            swp = nums[start], nums[start] = nums[end], nums[end] = swp;
        return;
    }

    int *sorted = nums + 1000000, mid = (start + end) / 2;
    mergesort(nums, start, mid);
    mergesort(nums, mid + 1, end);

    for (int i = start, l = mid + 1, pos = start; i <= mid || l <= end; ++pos)
    {
        if (i > mid)
            sorted[pos] = nums[l++];
        else if (l > end)
            sorted[pos] = nums[i++];
        else if (nums[i] < nums[l])
            sorted[pos] = nums[i++];
        else
            sorted[pos] = nums[l++];
    }

    memcpy(nums + start, sorted + start, sizeof(int) * (end - start + 1));
}

int main(void)
{
    int n;
    scanf("%d", &n);

    int nums[2000000];
    for (int i = 0; i < n; ++i)
        scanf("%d", &nums[i]);

    mergesort(nums, 0, n - 1);

    for (int i = 0; i < n; ++i)
        printf("%d\n", nums[i]);
    return 0;
}