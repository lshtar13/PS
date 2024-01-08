#include <bits/stdc++.h>

using namespace std;

typedef pair<int, string> word;
typedef vector<word> words;

int main(void)
{
    int n;
    scanf("%d", &n);

    words dicts(n);

    for (auto &x : dicts)
    {
        char aword[51] = {0};
        scanf("%s", aword);
        x.second = aword, x.first = x.second.length();
    }

    sort(dicts.begin(), dicts.end());

    printf("%s\n", dicts[0].second.c_str());
    for (int i = 1; i < n; ++i)
    {
        if (dicts[i].second == dicts[i - 1].second)
            continue;
        printf("%s\n", dicts[i].second.c_str());
    }

    return 0;
}