#include <bits/stdc++.h>

using namespace std;

unsigned int gap = UINT32_MAX, stotal = 0;
u_int8_t s[20][20];

void form(vector<int> &result, int limit, int length, map<int, bool> &remain)
{
    if (result.size() == length)
    {
        int start = 0;
        for (int i = 0; i < length; ++i)
            for (int l = 0; l < length; ++l)
                start += s[result[i] - 1][result[l] - 1];
        int link = 0;
        vector<int> result0;
        for (int i = 1; i <= limit; ++i)
            if (remain[i])
                result0.push_back(i);
        for (int i = 0; i < length; ++i)
            for (int l = 0; l < length; ++l)
                link += s[result0[i] - 1][result0[l] - 1];

        gap = min(gap, (unsigned int)abs(start - link));
    }
    else
        for (int i = result.size() ? result.back() + 1 : 1; i <= limit; ++i)
        {
            result.push_back(i);
            remain[i] = false;
            form(result, limit, length, remain);
            result.pop_back();
            remain[i] = true;
        }
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
        for (int l = 0; l < n; ++l)
        {
            scanf("%hhd", &s[i][l]);
            stotal += s[i][l];
        }

    map<int, bool> remain;
    for (int i = 1; i <= n; ++i)
        remain.insert({i, true});
    vector<int> result;
    form(result, n, n / 2, remain);
    printf("%d", gap);

    return 0;
}