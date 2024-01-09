#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    map<int, int> deck;
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        ++deck[x];
    }

    int m;
    scanf("%d", &m);
    for (int i = 0, x; i < m; ++i)
    {
        scanf("%d", &x);
        printf("%d ", deck[x]);
    }
    return 0;
}