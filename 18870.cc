#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> cord;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> cords(n);
    vector<int> result(n);
    for (int i = 0, x; i < n; ++i)
    {
        scanf("%d", &x);
        cords[i].first = x, cords[i].second = i;
    }

    sort(cords.begin(), cords.end());

    result[cords[0].second] = 0;
    for (int i = 1, cnt = 0; i < n; ++i)
    {
        if (cords[i - 1].first == cords[i].first)
            result[cords[i].second] = cnt;
        else
            result[cords[i].second] = ++cnt;
    }

    for (auto x : result)
        printf("%d ", x);

    return 0;
}