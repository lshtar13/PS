#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    char input[1001];
    scanf("%s", input);

    string s(input);
    int length = s.length();

    map<string, int> result;
    for (int i = 1; i <= length; ++i)
    {
        for (int l = 0; l <= length - i; ++l)
            result[s.substr(l, i)] += 1;
    }

    printf("%ld", result.size());

    return 0;
}