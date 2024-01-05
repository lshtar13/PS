#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    const int q = 25, d = 10, n = 5, p = 1;
    int t;
    cin >> t;
    while (t--)
    {
        int c, result[4] = {0};
        cin >> c;
        result[0] = c / q;
        c %= q;
        result[1] = c / d;
        c %= d;
        result[2] = c / n;
        c %= n;
        result[3] = c / p;
        c %= p;

        cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << endl;
    }

    return 0;
}