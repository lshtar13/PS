#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int freq[10] = {0};
    char c;
    while ((c = getchar()) != '\n')
    {
        ++freq[c - '0'];
    }

    for (int i = 9; i >= 0; --i)
    {
        if (freq[i])
            while (freq[i]--)
                printf("%d", i);
    }

    return 0;
}