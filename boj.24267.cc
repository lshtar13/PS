#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n;
    cin >> n;

    if (n <= 2)
        cout << 0 << endl
             << 3;
    else
        cout << (n - 1) * (n - 2) * (n - 1) / 2 - (n - 2) * (n - 1) * (2 * n - 3) / 6 << endl
             << 3;
    return 0;
}