#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    map<string, int> namebynum;
    map<int, string> numbyname;
    for (int i = 0; i < n; ++i)
    {
        char input[100];
        scanf("%s", input);

        string name(input);
        namebynum[name] = i + 1, numbyname[i + 1] = name;
    }

    for (int i = 0; i < m; ++i)
    {
        char input[100];
        scanf("%s", input);

        int num = atoi(input);
        if (num)
            printf("%s\n", numbyname[num].c_str());
        else
            printf("%d\n", namebynum[string(input)]);
    }

    return 0;
}