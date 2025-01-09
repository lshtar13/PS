#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    deque<pair<int, int>> dq;
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        dq.push_back({x, i + 1});
    }

    int num = 0;
    do
    {
        // printf("\nfront : %d  num : %d ", dq.front().second, num);
        if (num > 0)
        {
            for (int i = 0; i < num - 1; ++i)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }

            printf("%d ", dq.front().second);
            num = dq.front().first;
            dq.pop_front();
        }
        else if (num < 0)
        {
            for (int i = 0; i > num + 1; --i)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }

            printf("%d ", dq.back().second);
            num = dq.back().first;
            dq.pop_back();
        }
        else
        {
            printf("%d ", dq.front().second);
            num = dq.front().first;
            dq.pop_front();
        }
    } while (dq.size());
    return 0;
}