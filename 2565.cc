#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n, result = 1, e[100] = {1};
    scanf("%d", &n);
    vector<pair<int, int>> lines(n);

    for (auto &line : lines)
        scanf("%d %d", &line.first, &line.second);
    sort(lines.begin(), lines.end());

    for (int l, i = 1; i < n; ++i)
    {
        for (e[i] = 1, l = 0; l < i; ++l)
            if (lines[l].first < lines[i].first && lines[l].second < lines[i].second)
                e[i] = max(e[i], e[l] + 1);
        result = max(result, e[i]);
    }

    printf("%d", n - result);

    return 0;
}