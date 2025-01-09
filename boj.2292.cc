#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    --n;
    int result = 1;
    for (int i = 1; n > 0; ++i)
    {
        ++result;
        n -= 6 + (i - 1) * 6;
    }

    cout << result;

    return 0;
}