#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x;
    cin >> x;

    int i;
    for (i = 1; x > i; x -= i++)
        ;

    if (i == 1)
        cout << "1/1";
    else if (i % 2 == 0)
    {
        cout << x << "/" << i + 1 - x;
    }
    else
    {
        cout << i + 1 - x << "/" << x;
    }
    return 0;
}