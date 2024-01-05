#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    string n;
    int b, result = 0;

    cin >> n >> b;
    int l = n.length();
    l = pow(b, l - 1);
    for (char c : n)
    {
        if (c <= '9' && c >= '0')
        {
            result += (c - '0') * l;
        }
        else
        {
            result += (c - 'A' + 10) * l;
        }
        l /= b;
    }
    cout << result;
    return 0;
}