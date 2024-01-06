#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for (auto &k : nums)
        cin >> k;
    sort(nums.begin(), nums.end());

    int max = *max_element(nums.begin(), nums.end()), result = 0;
    vector<bool> fact(max + 1, true);
    fact[2] = false;
    for (int i = 2, pt = 0; i <= max;)
    {
        for (; nums[pt] < i; ++pt)
            ;
        if (nums[pt] == i)
            ++result;
        for (int l = i + 1; l <= max; ++l)
        {
            if (fact[l] && l % i == 0)
                fact[l] = false;
        }

        while (!fact[++i])
            ;
    }

    cout << result;

    return 0;
}