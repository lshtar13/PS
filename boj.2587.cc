#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int sum;
    cin >> sum;
    vector<int> nums;
    nums.push_back(sum);
    for (int i = 1; i < 5; ++i)
    {
        int n;
        cin >> n;
        sum += n;
        nums.push_back(n);
    }
    cout << sum / 5 << endl;
    sort(nums.begin(), nums.end());
    cout << nums[2];
    return 0;
}