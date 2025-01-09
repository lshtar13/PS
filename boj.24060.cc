#include <bits/stdc++.h>

using namespace std;

int k;

void merge(int arr[], int start, int mid, int end)
{
    int tmp[500001];
    int i = start, j = mid + 1, t = 0;
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }
    while (i <= mid)
        tmp[t++] = arr[i++];
    while (j <= end)
        tmp[t++] = arr[j++];
    i = start, t = 0;
    while (i <= end)
    {
        int num = arr[i++] = tmp[t++];
        if (--k == 0)
            printf("%d", num);
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(void)
{
    int n;
    scanf("%d %d", &n, &k);

    int arr[500001];
    for (int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    if (k > 0)
        printf("-1");
    return 0;
}