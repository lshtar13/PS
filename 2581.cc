#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int m, n;
    cin >> m >> n;

    int sum = 0, min;
    vector<bool> fact(n + 1, true);
    fact[2] = false;
    for (int i = 2, pt = 0; i <= n;)
    {
        if (i <= n && i >= m)
        {
            if (sum == 0)
                min = i;
            sum += i;
        }

        for (int l = i + 1; l <= n; ++l)
        {
            if (fact[l] && l % i == 0)
                fact[l] = false;
        }

        while (!fact[++i])
            ;
    }

    if (sum == 0)
        cout << -1;
    else
        cout << sum << endl
             << min;

    return 0;
}