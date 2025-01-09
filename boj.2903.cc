#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;

    n++;
    n = pow(2, n - 1) + 1;
    n = n * n;
    cout << n;

    return 0;
}