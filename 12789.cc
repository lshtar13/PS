#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);

    vector<int> line0(n);
    for (auto &x : line0)
        scanf("%d", &x);

    reverse(line0.begin(), line0.end());
    vector<int> line1;
    for (int i = 1; i <= n; ++i)
    {
        if (line1.size() && line1.back() == i)
        {
            line1.pop_back();
            continue;
        }

        while (line0.size() && line0.back() != i)
        {
            line1.push_back(line0.back());
            line0.pop_back();
        }

        if (line0.size() && line0.back() == i)
            line0.pop_back();
        else
        {
            printf("Sad");
            return 0;
        }
    }

    printf("Nice");

    return 0;
}