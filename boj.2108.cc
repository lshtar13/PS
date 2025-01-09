#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    double sum = 0;
    map<int, int> frq;
    vector<int> nums(n);
    int max = 0;
    for (auto &x : nums)
    {
        scanf("%d", &x);
        sum += x;
        frq[x] ? frq[x] += 1 : frq[x] = 1;
        frq[x] > max ? max = frq[x] : 0;
    }

    sort(nums.begin(), nums.end());

    printf("%d\n", int(round(sum / double(n)) + 0.0));
    printf("%d\n", nums[nums.size() / 2]);
    int mfrq;
    for (auto &x : frq)
    {
        static int i = 0;
        if (i == 2)
            break;
        if (x.second == max)
            ++i, mfrq = x.first;
    }
    printf("%d\n", mfrq);
    printf("%d\n", nums[nums.size() - 1] - nums[0]);
    return 0;
}