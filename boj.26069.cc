#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    string cc = "ChongChong";
    map<string, bool> dance;
    dance.insert({cc, true});
    for (int i = 0; i < n; ++i)
    {
        string name0, name1;
        cin >> name0 >> name1;
        if (dance[name0])
            dance[name1] = true;
        else if (dance[name1])
            dance[name0] = true;
    }

    int result = 0;
    for (auto &record : dance)
        result += record.second ? 1 : 0;
    printf("%d", result);

    return 0;
}