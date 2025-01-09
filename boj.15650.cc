#include <bits/stdc++.h>

using namespace std;

void form(vector<int> &result, int limit, int length)
{
    if (result.size() == length)
    {
        for (auto &x : result)
            printf("%d ", x);
        printf("\n");
    }
    else
        for (int i = result.size() ? result.back() + 1 : 1; i <= limit; ++i)
        {
            result.push_back(i);
            form(result, limit, length);
            result.pop_back();
        }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> result;

    form(result, n, m);
    return 0;
}