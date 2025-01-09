#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a + b + c == 0)
            break;

        int longest = max(max(a, b), c);
        if (a + b + c <= longest * 2)
            cout << "Invalid" << endl;
        else if (a == b && a == c)
            cout << "Equilateral" << endl;
        else if (a == b || a == c || b == c)
            cout << "Isosceles" << endl;
        else
            cout << "Scalene" << endl;
    }
    return 0;
}