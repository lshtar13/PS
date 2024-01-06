#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b + c != 180)
        cout << "Error";
    else if (a == b && a == c)
        cout << "Equilateral";
    else if (a == c || b == c || a == b)
        cout << "Isosceles";
    else
        cout << "Scalene";

    return 0;
}