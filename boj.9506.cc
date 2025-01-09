#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == -1)
            break;

        int sum = 0, factor[100000] = {0}, nfactor = 0;
        for (int i = 1; i < n; ++i)
            if (n % i == 0)
                sum += i, factor[nfactor++] = i;

        if (sum == n)
        {
            cout << n << " = " << 1;
            for (int i = 1; i < nfactor; ++i)
                cout << " + " << factor[i];
        }
        else
            cout << n << " is NOT perfect.";

        cout << endl;
    }

    return 0;
}