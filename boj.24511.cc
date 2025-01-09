#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<bool> isQ(n);
    deque<int> q;
    for (int i = 0, a; i < n; ++i)
    {
        scanf("%d", &a);
        isQ[i] = !a;
    }

    for (int i = 0, b; i < n; ++i)
    {
        scanf("%d", &b);
        if (isQ[i])
            q.push_back(b);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0, c, result; i < m; ++i)
    {
        scanf("%d", &c);
        result = c;
        if (q.size())
        {
            q.push_front(c);
            result = q.back();
            q.pop_back();
        }
        printf("%d ", result);
    }
    return 0;
}