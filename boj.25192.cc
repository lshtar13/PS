#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    map<string, bool> usrlist;
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
        char str[21];
        scanf("%s", str);

        if (!strcmp(str, "ENTER"))
        {
            result += usrlist.size();
            usrlist.clear();
            continue;
        }

        string name = str;
        usrlist[name] = true;
    }
    result += usrlist.size();

    printf("%d", result);
    return 0;
}