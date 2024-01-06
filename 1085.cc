#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    w -= x, h -= y;
    int result = min(x, y);
    result = min(result, w);
    result = min(result, h);
    cout << result;
    return 0;
}