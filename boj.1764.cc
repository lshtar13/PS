#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    map<string, bool> see;
    for (int i = 0; i < n; ++i)
    {
        char input[21];
        scanf("%s", input);

        string name(input);
        see[name] = true;
    }

    map<string, bool> result;
    for (int i = 0; i < m; ++i)
    {
        char input[21];
        scanf("%s", input);

        string name(input);
        if (see[name])
            result[name] = true;
    }

    printf("%ld\n", result.size());
    for (auto &x : result)
        printf("%s\n", x.first.c_str());

    return 0;
}