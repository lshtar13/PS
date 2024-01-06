#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    double a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;

    if (c == a1)
        if (a0 <= 0)
            cout << 1;
        else
            cout << 0;
    else if (c < a1)
        cout << 0;
    else if (n0 >= a0 / (c - a1))
        cout << 1;
    else
        cout << 0;

    return 0;
}