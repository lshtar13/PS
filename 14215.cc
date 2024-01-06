#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    int longest = max(max(a, b), c);
    int gap = longest * 2 - a - b - c;

    int result = a + b + c;
    if (gap >= 0)
        result -= gap + 1;
    cout << result;
    return 0;
}