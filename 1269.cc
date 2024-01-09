#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);

    map<int, bool> A;
    for (int i = 0, x; i < a; ++i)
    {
        scanf("%d", &x);
        A[x] = true;
    }

    int inter = 0;
    for (int i = 0, x; i < b; ++i)
    {
        scanf("%d", &x);
        if (A[x])
            ++inter;
    }

    printf("%d", a + b - 2 * inter);

    return 0;
}