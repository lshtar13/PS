#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> cord;
typedef vector<cord> cords;

int main(void)
{
    int n;
    scanf("%d", &n);

    cords nums(n);
    for (int i = 0; i < n; ++i)
        scanf("%d %d", &nums[i].second, &nums[i].first);

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; ++i)
        printf("%d %d\n", nums[i].second, nums[i].first);

    return 0;
}