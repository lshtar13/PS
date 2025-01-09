#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    map<string, bool> attend;
    for (int i = 0; i < n; ++i)
    {
        char _name[6], record[6];
        scanf("%s %s", _name, record);
        string name(_name);

        if (!strncmp(record, "enter", 5))
            if (!attend[name])
                attend[name] = true;
            else
                ;
        else if (!strncmp(record, "leave", 5))
            if (attend[name])
                attend[name] = false;
    }

    for (auto it = attend.rbegin(), end = attend.rend(); it != end; ++it)
        if (it->second)
            printf("%s\n", it->first.c_str());

    return 0;
}