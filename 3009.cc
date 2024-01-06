#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x = 0, y = 0;
    for (int i = 0, xx, yy; i < 3; ++i)
    {
        cin >> xx >> yy;
        x ^= xx, y ^= yy;
    }
    cout << x << " " << y;

    return 0;
}