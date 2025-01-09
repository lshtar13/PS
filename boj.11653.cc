#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    if (n == 1)
        return 0;

    for (int i = 2; i <= n; ++i)
    {
        for (; n % i == 0; n /= i)
            cout << i << endl;
    }
    return 0;
}