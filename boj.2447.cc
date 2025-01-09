#include <bits/stdc++.h>

using namespace std;

char result[6562][6562];

void fill(int n, int start, int end)
{
    if (n == 1)
    {
        result[start][end] = '*';
    }
    else
    {
        int gap = n / 3;
        for (int i = 0; i < gap * 3; i += gap)
        {
            fill(gap, start, end + i);
            fill(gap, start + 2 * gap, end + i);
        }
        fill(gap, start + gap, end);
        fill(gap, start + gap, end + 2 * gap);

        for (int i = 0; i < gap; ++i)
            for (int l = 0; l < gap; ++l)
                result[start + gap + i][end + gap + l] = ' ';
    }
}

int main(void)
{
    int n;
    scanf("%d", &n);
    fill(n, 0, 0);
    for (int i = 0; i < n; ++i)
    {
        for (int l = 0; l < n; ++l)
            printf("%c", result[i][l]);
        printf("\n");
    }
    return 0;
}