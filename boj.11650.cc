#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> cord;
typedef vector<cord> cords;

inline ll cordhash(cord num) { return num.first * 200000 + num.second * 20000; }

cord swp;
void quicksort0(cords &nums, int start, int end)
{
    if (start >= end)
        return;

    cord pivot = nums[start];
    int low = start + 1, high = end;
    while (low <= high)
    {
        if (cordhash(nums[low]) <= cordhash(pivot))
            ++low;
        if (cordhash(nums[high]) >= cordhash(pivot))
            --high;

        if (cordhash(nums[low]) <= cordhash(pivot) && cordhash(nums[high]) >= cordhash(pivot))
            swp = nums[low], nums[low] = nums[high], nums[high] = swp;
    }

    nums[start] = nums[high], nums[high] = pivot;
    quicksort0(nums, start, high - 1);
    quicksort0(nums, high + 1, end);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    cords nums(n);
    for (int i = 0; i < n; ++i)
        scanf("%lld %lld", &nums[i].first, &nums[i].second);

    // quicksort0(nums, 0, n - 1);
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i)
        printf("%lld %lld\n", nums[i].first, nums[i].second);

    return 0;
}