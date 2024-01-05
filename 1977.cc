#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int m, n;
    std::cin >> m >> n;

    int start = (int)sqrt(m), end = (int)sqrt(n), sum = 0, min = 1000000;
    if (start * start < m)
        start++;
    for (int i = start; i <= end; ++i)
    {
        sum += i * i;
        if (i * i < min)
            min = i * i;
    }
    if (sum)
        std::cout << sum << std::endl
                  << min;
    else
        std::cout << -1;
    return 0;
}