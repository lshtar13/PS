#include <bits/stdc++.h>

using namespace std;

void form(vector<int> &remain, vector<int> &result, int length)
{
    if (result.size() == length)
    {
        for (auto &x : result)
            printf("%d ", x);
        printf("\n");
    }

    else
        for (int i = 0, l = remain.size(); i < l; ++i)
        {
            int num = remain[i];
            result.push_back(num);
            remain.erase(remain.begin() + i);
            form(remain, result, length);
            remain.insert(remain.begin() + i, num);
            result.pop_back();
        }
}

int main(void)
{
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> remain, result;
    for (int i = 1; i <= n; ++i)
        remain.push_back(i);

    form(remain, result, m);
    return 0;
}