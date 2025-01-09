#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, b;
    cin >> n >> b;

    string result;
    for (char k = n % b; n; n /= b, k = n % b)
    {
        if (k < 10)
        {
            result.append(1, k + '0');
        }
        else
        {
            result.append(1, k - 10 + 'A');
        }
    }

    reverse(result.begin(), result.end());
    cout << result;

    return 0;
}