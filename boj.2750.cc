#include <bits/stdc++.h>

using namespace std;

int search(int tgt, int start, int end, vector<int> &nums)
{
    if (start == end)
        if (nums[start] > tgt)
            return start;
        else
            return start + 1;

    int mid = (start + end) / 2;
    if (tgt > nums[mid])
        return search(tgt, mid + 1, end, nums);
    else
        return search(tgt, start, mid, nums);
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> nums(n, 0);
    cin >> nums[0];
    for (int i = 1; i < n; ++i)
    {
        int num;
        cin >> num;

        int index = search(num, 0, i - 1, nums);
        nums.insert(nums.begin() + index, 1, num);

        // for (auto x : nums)
        //     cout << x << " ";
        // cout << endl;
    }

    for (int i = 0; i < n; ++i)
        cout << nums[i] << endl;

    return 0;
}