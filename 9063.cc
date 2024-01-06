#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long n, xmin = LLONG_MAX, xmax = LLONG_MIN, ymin = LLONG_MAX, ymax = LLONG_MIN;

    cin >> n;
    if (n < 2)
    {
        cout << 0;
        return 0;
    }

    for (long long i = 0, x, y; i < n; ++i)
    {
        cin >> x >> y;
        xmin = min(xmin, x);
        ymin = min(ymin, y);
        xmax = max(xmax, x);
        ymax = max(ymax, y);
    }

    cout << (long long)((xmax - xmin) * (ymax - ymin));
    return 0;
}