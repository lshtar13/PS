#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    scanf("%d", &n);
    vector<int> times(n, 0);
    for (auto &time : times)
        scanf("%d", &time);

    sort(times.begin(), times.end());

    int result = 0;
    for (int i = 0; i < n; ++i)
        result += (n - i) * times[i];
    printf("%d", result);
    return 0;
}