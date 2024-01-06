#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    int factor = 1;
    for (int i = 1; i < k; ++i)
    {
        factor++;
        for (; n % factor != 0 && factor <= n; ++factor)
            ;
    }

    if (factor <= n)
        cout << factor;
    else
        cout << 0;

    return 0;
}