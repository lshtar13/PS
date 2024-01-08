#include <bits/stdc++.h>

using namespace std;

int search(int tgt, int start, int end, vector<int> &nums)
{
    if (start == end)
        if (tgt <= nums[start])
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
    int n, k;
    cin >> n >> k;

    vector<int> topk(k, -1);
    while (n--)
    {
        int num;
        cin >> num;

        if (num < topk[0])
            continue;

        topk.insert(topk.begin() + search(num, 0, k - 1, topk), num);
        topk.erase(topk.begin());

        // for (auto x : topk)
        //     cout << x << " ";
        // cout << endl;
    }
    cout << *topk.begin();
    return 0;
}