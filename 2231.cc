#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    for (int i = 1; i < n; ++i)
    {
        int sum = i, _i = i;
        while (_i)
            sum += _i % 10, _i /= 10;
        if (sum == n)
        {
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}